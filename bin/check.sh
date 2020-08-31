#!/bin/bash

set -e -x

SCRIPT_LOCATION=$(readlink -f $(dirname $0))

date=$(date +%s)

BENCHMARKS=${SCRIPT_LOCATION}/../benchmarks/exp_benchmarks/*.fpcore

${SCRIPT_LOCATION}/fptuner \
                  ${BENCHMARKS} \
                  --nightly -e 1e1 1e0 1e-1 1e-2 1e-3  1e-4  1e-5 1e-6  1e-7 \
                  --cfile \
    | tee $date.html

scp $date.html uwplse.org:/var/www/fptuner/
scp ${SCRIPT_LOCATION}/cost-measurement/*.png $date.html uwplse.org:/var/www/fptuner/

