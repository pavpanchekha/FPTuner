#!/usr/bin/env python3

from generation_utils import *

if __name__ == "__main__":
    funcs = read_all_json(sys.argv[1])


    print("exp")
    exps = [f for f in funcs if f["function"] == "exp(x)"]
    print_tsv(exps)

    print("log")
    logs = [f for f in funcs if f["function"] == "log(1+x)"]
    print_tsv(logs)

    print("sin")
    sins = [f for f in funcs if f["function"] == "sin(x)"]
    print_tsv(sins)

    print("tan")
    tans = [f for f in funcs if f["function"] == "tan(x)"]
    print_tsv(tans)
