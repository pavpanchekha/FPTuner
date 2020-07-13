

from exceptions import FPTaylorFormError, FPTaylorRuntimeError
from fpcore_logging import Logger
from fptaylor_form import FPTaylorForm
from fptaylor_lexer import FPTaylorLexer
from fptaylor_parser import FPTaylorParser

import shlex
import subprocess
import tempfile


logger = Logger(level=Logger.MEDIUM, color=Logger.blue)


class FPTaylorResult:
    # Default configuration for FPTaylor when being used for finding FPTaylor
    # forms
    ERROR_FORM_CONFIG = {
        "--abs-error": "false",
        "--find-bounds": "false",
        "--fp-power2-model": "false",
        "--fail-on-exception": "false",
        "--unique-indices": "true",
    }

    # Default configuration for FPTaylor when being used to check answers given
    # by FPTuner. Try for the best answer possible.
    CHECK_CONFIG = {
        "--abs-error": "true",
        "--fp-power2-model": "true",
        "--opt": "gelpia",
        "--opt-exact": "true",
        "--opt-f-rel-tol": "0",
        "--opt-f-abs-tol": "0",
        "--opt-x-rel-tol": "0",
        "--opt-x-abs-tol": "0",
        "--opt-max-iters": "0",
        "--opt-timeout": "0",
    }

    def __init__(self, query, config=None):
        logger.llog(logger.HIGH, "Query:\n{}", query)
        self.abs_error = None
        self.high_second_order = None
        self.query = query
        self.config = config or FPTaylorResult.ERROR_FORM_CONFIG
        self._run()
        self._extract_fptaylor_forms()

    def _run(self):
        # Open a tempfile we can hand to FPTaylor.
        # The file will be removed upon exiting the with block
        with tempfile.NamedTemporaryFile("w") as f:

            # Write out the query and make sure it is filled
            f.write(self.query)
            f.flush()

            # Put together the FPTaylor command
            flags = " ".join([k+" "+v for k, v in self.config.items()])
            command = "fptaylor {} {}".format(flags, f.name)
            logger.llog(Logger.HIGH, "Command: {}", command)

            # Call FPTaylor
            with subprocess.Popen(shlex.split(command),
                                  stdout=subprocess.PIPE,
                                  stderr=subprocess.PIPE) as p:

                # Make sure that the run is complete and grab output
                # todo: should there be a timeout?
                raw_out, raw_err = p.communicate()
                self.out = raw_out.decode("utf8")
                self.err = raw_err.decode("utf8")
                self.retcode = p.returncode

        # If anything went wrong in the call unceremoniusly exit
        if self.retcode != 0:
            raise FPTaylorRuntimeError(self.query,
                                       command,
                                       self.out,
                                       self.err,
                                       self.retcode)

        logger.llog(Logger.HIGH, "stdout:\n{}", self.out.strip())

        # Grab when FPTaylor warns about second order error
        err_lines = self.err.splitlines()
        high_msg = "**WARNING**: Large second-order error:"
        help_msg = "**WARNING**: Try intermediate-opt"
        self.high_second_order = any([high_msg in line for line in err_lines])
        err_lines = [line for line in err_lines if line.strip() != ""]
        err_lines = [line for line in err_lines if high_msg not in line]
        err_lines = [line for line in err_lines if help_msg not in line]

        # Error when FPTaylor complains about infinity and domain errors
        # todo: handle when this occurs
        if len(err_lines) != 0:
            if not logger.should_log(Logger.HIGH):
                logger.llog(logger.NONE, "Query:\n{}", self.query)
                logger.llog(Logger.NONE, "Command: {}", command)
                logger.llog(Logger.NONE, "stdout:\n{}", self.out.strip())
            logger.error("stderr:\n{}", "\n".join(err_lines))

    def _extract_fptaylor_forms(self):
        # Since FPTaylor forms are listed seperate from their corresponding
        # original expressions we will capture both and realign them after
        fptaylor_forms = dict()
        original_exprs = dict()

        # Get the expression parser ready
        lexer = FPTaylorLexer()
        parser = FPTaylorParser()

        # todo: fix hacky state parser
        state = "find fptaylor forms"
        for line in self.out.splitlines():
            line = line.strip()
            items = line.split()

            if state == "find fptaylor forms":
                # Look for the start of the fptaylor forms
                if len(items) > 0 and line.split()[0] == "v0":
                    state = "capture fptaylor forms"
                continue

            if state == "capture fptaylor forms":
                # Grab fptaylor forms and look for the end of fptaylor forms
                if line == "":
                    state = "find original expr"
                    continue
                # Match on:
                #   0       1        2   3 4      5...
                #   |       |        |   | |      |
                #   <index> (<int>): exp = <exp>: <expr>
                index = int(items[0])
                exp = items[4].replace(":", "")
                expr = " ".join(items[5:])
                form = FPTaylorForm(exp, expr)
                fptaylor_forms[index] = form
                continue

            if state == "find original expr":
                # Look for the start of original subexpressions
                if line == "Corresponding original subexpressions:":
                    state = "capture original exprs"
                continue

            if state == "capture original exprs":
                # Grab original subexpressions and look for their end
                if line == "":
                    state = "capture error"
                    continue
                # Match on:
                #   0        1...
                #   |        |
                #   <index>: <expr>
                index = int(items[0].replace(":", ""))
                expr = " ".join(items[1:])
                tokens = lexer.tokenize(expr)
                parsed = parser.parse(tokens)
                original_exprs[index] = parsed
                continue

            if state == "capture error":
                first = "Absolute error (exact):"
                if line.startswith(first):
                    self.abs_error = float(line[len(first):])
                    break
                continue

        # Combine both dicts in order
        logger("Original -> FPtaylor Form")
        forms = list()
        for index in sorted(original_exprs):
            o = original_exprs[index]
            f = fptaylor_forms[index]
            logger("{} -> {}", o, f)
            forms.append((o, f))

        if self.abs_error is not None:
            logger("abs_error: {}", self.abs_error)

        self.fptaylor_forms = forms
