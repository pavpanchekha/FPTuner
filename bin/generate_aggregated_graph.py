#!/usr/bin/env python3

import os.path as path
import matplotlib.pyplot as plt
import os
import subprocess
import sys
import shlex
import json
import math

PYTHON_DIR = path.abspath(path.dirname(__file__))
GIT_DIR = path.split(PYTHON_DIR)[0]
COST_DIR = path.join(GIT_DIR, "cost-measurement")
sys.path.append(path.join(GIT_DIR, "src"))
sys.path.append(path.join(GIT_DIR, "src", "fptaylor"))
sys.path.append(path.join(GIT_DIR, "src", "fpcore_parser", "src"))


def aggregate_graph(filenames):
    pointss = read_all(filenames)
    graph(pointss, "aggragate")

def graph(pointss, outname, dump_file=None):
    errors = list()
    speedups = list()
    for points in pointss:
        print(points)
        error = math.exp(sum([math.log(x) for x, y in points]) / len(points))
        speedup = math.exp(-sum([math.log(y) for x, y in points]) / len(points))
        errors.append(error)
        speedups.append(speedup)

    # dump data
    if dump_file is None:
        dump_file = path.join(COST_DIR, "{}.data".format(outname))
    with open(dump_file, 'w') as f:
        f.write("errors = {}\n".format(errors))
        f.write("speedups = {}\n".format(speedups))

    # plot
    fig, ax = plt.subplots()
    ax.scatter(errors, speedups)
    ax.set_xscale('log')
    ax.set_xlabel("Error")
    xmin, xmax = ax.set_xlim()
    ax.set_xlim(xmax, xmin)
    ax.set_ylabel("Speedup")
    ax.set_title("Aggregate")

    fig.savefig("{}.png".format(outname))


def read_all(filenames):
    start = os.getcwd()
    os.chdir(COST_DIR)

    data = list()
    for fname in file_list:
        with open(fname) as f:
            raw_datum = read(f)
            normalized = normalize(raw_datum)
            data.append(normalized)

    pointss = zip(*data)

    os.chdir(start)


def read(fd):
    l = fd.readline()
    errors = [float(x) for x in l[l.find("[") + 1:l.find("]")].split(", ")]
    l = fd.readline()
    averages = [float(x) for x in l[l.find("[") + 1:l.find("]")].split(", ")]
    return list(zip(errors, averages))

def normalize(l):
    last_x, last_y = l[-1]
    return [(x / last_x, y / last_y) for x, y in l]

if __name__ == "__main__":
    data = []
    for l in sys.argv[1:]:
        with open(l) as fd:
            data.append(normalize(read(fd)))
    pointss = zip(*data)
    graph(pointss, "aggregate")
