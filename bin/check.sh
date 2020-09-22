#!/bin/bash

set -e -x

SCRIPT_LOCATION=$(readlink -f $(dirname $0))

if [ "$(hostname)" = "warfa" ]; then
    git clean -dfx
fi

date=$(date +%s)

FPTUNER="${SCRIPT_LOCATION}/fptuner --nightly --cfile"

mkdir $date
cat <<EOF > $date/index.html
<!doctype html>
<title>FPTuner Results for $(date +%Y-%m-%d)</title>
<body>
EOF
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/azimuth.fpcore -e 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/complex_sine_and_cosine.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/exp1x.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 1e-11 1e-12 1e-13 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/exp1x_log.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 1e-11 1e-12 1e-13 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/hartman3.fpcore -e 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/hartman6.fpcore -e 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/i6.fpcore -e 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/logexp2.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 1e-11 1e-12 1e-13 1e-14 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/logexp.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 1e-11 1e-12 1e-13 1e-14 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/nmse_example_3_7.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/nmse_problem_3_3_7.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/nmse_problem_3_4_2.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/nmse_problem_3_4_4.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 1e-11 1e-12 1e-13 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/nmse_section_3_11.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 1e-11 1e-12 1e-13 1e-14 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/sine.fpcore -e 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/sineOrder3.fpcore -e 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/sphere.fpcore -e 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 | tee -a $date/index.html
${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/Statistics_Distribution_Poisson_Internal_probability_from_math_functions_0_1_5_2.fpcore  -e 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 | tee -a $date/index.html

cat <<EOF >> $date/index.html
</body>
EOF

mv ${SCRIPT_LOCATION}/../cost-measurement/*.png $date
mv ${SCRIPT_LOCATION}/../cost-measurement/*.data $date

if [ "$(hostname)" = "warfa" ]; then
    scp -r $date uwplse.org:/var/www/fptuner/
fi
