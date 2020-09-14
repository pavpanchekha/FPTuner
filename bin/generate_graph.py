#!/usr/bin/env python3

import os.path as path
import matplotlib.pyplot as plt
import os
import subprocess
import sys

PYTHON_DIR = path.abspath(path.dirname(__file__))
GIT_DIR = path.split(PYTHON_DIR)[0]
COST_DIR = path.join(GIT_DIR, "cost-measurement")
sys.path.append(path.join(GIT_DIR, "src"))
sys.path.append(path.join(GIT_DIR, "src", "fptaylor"))
sys.path.append(path.join(GIT_DIR, "src", "fpcore_parser", "src"))

def graph(main_file):
    # > cd cost-measurement
    start = os.getcwd()
    os.chdir(COST_DIR)

    # > make
    with subprocess.Popen("make", stdout=subprocess.PIPE, stderr=subprocess.PIPE) as p:
        raw_out, raw_error = p.communicate()
        assert p.returncode == 0, raw_error.decode("utf8")

    # > ./bin/<main_file>
    with subprocess.Popen("./bin/{}".format(main_file.rstrip(".c")),
                          stdout=subprocess.PIPE,
                          stderr=subprocess.PIPE) as p:
        raw_out, raw_error = p.communicate()
        out = raw_out.decode("utf8")
        assert p.returncode == 0, raw_error.decode("utf8")

    # parse output
    rows = out.splitlines()
    rows = [row.split("\t") for row in rows]
    averages = list()
    errors = list()
    secs = None
    for row in rows:
        if row[0] in {"", "values", "function"}:
            continue
        if row[0] == "secs":
            secs = int(row[1])
            continue
        name = row[0]
        error = row[1]
        counts = [int(col) for col in row[2:]]
        times = [secs/c for c in counts]
        avg = sum(times) / len(times) * 1e9
        averages.append(avg)
        errors.append(float(error))

    # dump data
    with open("{}.data".format(main_file.rstrip(".c")), 'w') as f:
        f.write("errors = {}\n".format(errors))
        f.write("averages = {}\n".format(averages))

    # plot
    fig, ax = plt.subplots()
    ax.scatter(errors, averages)
    ax.set_xscale('log')
    ax.set_xlabel("Error")
    xmin, xmax = ax.set_xlim()
    ax.set_xlim(xmax, xmin)
    ax.set_ylabel("Time (ns)")
    ax.set_title(main_file.rstrip(".c"))

    fig.savefig("{}.png".format(main_file.rstrip(".c")))

    os.chdir(start)



if __name__ == "__main__":
    graph(sys.argv[1])
