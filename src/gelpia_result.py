

from exceptions import GelpiaInfError
from fpcore_logging import Logger
from fractions import Fraction
from math import isinf
from multiprocessing import Process, Value

import gelpia
import gelpia_logging


logger = Logger(level=Logger.MEDIUM, color=Logger.green)


class GelpiaResult:

    # Setup logging to avoid runtime error
    gelpia_logging.set_log_filename(None)

    # Silence gelpia
    gelpia_logging.set_log_level(-10)

    # Setup gelpia's env
    gelpia.setup_requirements(git_dir=gelpia.GIT_DIR)

    # Setup rust's env
    RUST_EXECUTABLE = gelpia.setup_rust_env(git_dir=gelpia.GIT_DIR,
                                            debug=False)

    # Tell gelpia how hard to try
    CONFIG = {
        "epsilons": (1e-8, 1e-8, 0),
        "timeout": 10,
        "grace": 0,
        "update": 0,
        "iters": 0,
        "seed": 0,
        "debug": False,
        "src_dir": gelpia.SRC_DIR,
        "executable": RUST_EXECUTABLE,
    }

    def __init__(self, inputs, expr):
        # Format inputs, target expression, and set as member
        # todo: this float cast can loose information
        lines = ["{} = [{}, {}];".format(name,
                                         float(Fraction(domain[0].source)),
                                         float(Fraction(domain[1].source)))
                 for name, domain in inputs.items()]
        lines.append(expr.infix_str())
        self.query = "\n".join(lines)
        logger.log("query:\n{}", self.query)

        # Run and set results as member
        max_lower = Value("d", float("nan"))
        max_upper = Value("d", float("nan"))
        max_args = {"function": self.query,
                    "max_lower": max_lower,
                    "max_upper": max_upper}
        max_args.update(GelpiaResult.CONFIG)
        p = Process(target=gelpia.find_max, kwargs=max_args)

        p.start()

        self.min_lower, self.min_upper = gelpia.find_min(function=self.query,
                                                         **GelpiaResult.CONFIG)

        p.join()

        self.max_lower = max_lower.value
        self.max_upper = max_upper.value

        self.abs_max = max(self.max_upper, -self.min_lower)

        if isinf(self.abs_max):
            raise GelpiaInfError(self.query)

        logger.llog(Logger.HIGH, "min = [{}, {}]",
                    self.min_lower, self.min_upper)
        logger.llog(Logger.HIGH, "max = [{}, {}]",
                    self.max_lower, self.max_upper)
        logger.llog(Logger.HIGH, "abs_max = {}",
                    self.abs_max)

