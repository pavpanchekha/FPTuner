#!/bin/bash

set -e -x

SCRIPT_LOCATION=$(readlink -f $(dirname $0))

date=$(date +%s)

BENCHMARKS=${SCRIPT_LOCATION}/../benchmarks/supported_fpcores/*.fpcore

${SCRIPT_LOCATION}/fptuner \
                  ${BENCHMARKS} \
                  --nightly -e 1e1 1e0 1e-1 1e-2 1e-3  1e-4  1e-5 1e-6  1e-7 \
                  >> $date.html

scp $date.html uwplse.org:/var/www/fptuner/

