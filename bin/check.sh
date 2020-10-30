#!/bin/bash

set -e -x

SCRIPT_LOCATION=$(readlink -f $(dirname $0))

rm -rf ${SCRIPT_LOCATION}/../cost-measurement/kerns

date=$(date +%s)

FPTUNER="${SCRIPT_LOCATION}/fptuner --nightly --cfile"


run ()
{
    \time -f %e ${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/$1 -v medium -e ${@:2} | tee -a $date/index.html
    echo -e "\n\n\n\n" >> $date/index.html
}

mkdir $date
cat <<EOF > $date/index.html
<!doctype html>
<title>FPTuner Results for $(date +%Y-%m-%d)</title>
<body>
EOF

BINADES=( 128 16 2 0.25 0.03125 0.00390625 0.00048828125 6.103515625e-05 7.62939453125e-06 9.5367431640625e-07 1.1920928955078125e-07 1.4901161193847656e-08 1.862645149230957e-09 2.3283064365386963e-10 2.9103830456733704e-11 3.637978807091713e-12 )

run azimuth.fpcore ${BINADES[@]}
run complex_sine_and_cosine.fpcore ${BINADES[@]}
run Data_HyperLogLog_Type_size_from_hyperloglog_0_3_4_A.fpcore ${BINADES[@]}
run Data_Number_Erf_dmerfcx_from_erf_2_0_0_0.fpcore ${BINADES[@]}
run Data_Random_Distribution_Normal_normalF_from_random_fu_0_2_6_2.fpcore ${BINADES[@]}
run Diagrams_ThreeD_Transform_aboutX_from_diagrams_lib_1_3_0_3_A.fpcore ${BINADES[@]}
run Diagrams_ThreeD_Transform_aboutX_from_diagrams_lib_1_3_0_3_B.fpcore ${BINADES[@]}
run Diagrams_ThreeD_Transform_aboutY_from_diagrams_lib_1_3_0_3.fpcore ${BINADES[@]}
run Diagrams_TwoD_Path_Metafont_Internal_hobbyF_from_diagrams_contrib_1_3_0_5.fpcore ${BINADES[@]}
run exp1x_32.fpcore ${BINADES[@]}
run exp1x.fpcore ${BINADES[@]}
run exp1x_log.fpcore ${BINADES[@]}
run hartman3.fpcore ${BINADES[@]}
# run hartman6.fpcore ${BINADES[@]}
run i6.fpcore ${BINADES[@]}
run Linear_Quaternion_cexp_from_linear_1_19_1_3.fpcore ${BINADES[@]}
run logexp2.fpcore ${BINADES[@]}
run logexp.fpcore ${BINADES[@]}
run nmse_example_3_10.fpcore ${BINADES[@]}
run nmse_example_3_3.fpcore ${BINADES[@]}
run nmse_example_3_4.fpcore ${BINADES[@]}
run nmse_example_3_7.fpcore ${BINADES[@]}
run nmse_example_3_8.fpcore ${BINADES[@]}
run nmse_problem_3_3_2.fpcore ${BINADES[@]}
run nmse_problem_3_3_6.fpcore ${BINADES[@]}
run nmse_problem_3_3_7.fpcore ${BINADES[@]}
run nmse_problem_3_4_2.fpcore ${BINADES[@]}
run nmse_problem_3_4_4.fpcore ${BINADES[@]}
run nmse_section_3_11.fpcore ${BINADES[@]}
run nmse_section_3_5.fpcore ${BINADES[@]}
run Numeric_SpecFunctions_invIncompleteBetaWorker_from_math_functions_0_1_5_2_B.fpcore ${BINADES[@]}
run Numeric_SpecFunctions_logBeta_from_math_functions_0_1_5_2_A.fpcore ${BINADES[@]}
run Numeric_SpecFunctions_logBeta_from_math_functions_0_1_5_2_B.fpcore ${BINADES[@]}
run Numeric_SpecFunctions_logGammaL_from_math_functions_0_1_5_2.fpcore ${BINADES[@]}
run Numeric_SpecFunctions_slogFactorial_from_math_functions_0_1_5_2_B.fpcore ${BINADES[@]}
run Numeric_SpecFunctions_stirlingError_from_math_functions_0_1_5_2.fpcore ${BINADES[@]}
run sphere.fpcore ${BINADES[@]}
run Statistics_Distribution_Beta_cdensity_from_math_functions_0_1_5_2.fpcore ${BINADES[@]}
run Statistics_Distribution_Binomial_directEntropy_from_math_functions_0_1_5_2.fpcore ${BINADES[@]}
run Statistics_Distribution_Poisson_clogProbability_from_math_functions_0_1_5_2.fpcore ${BINADES[@]}
run Statistics_Distribution_Poisson_Internal_probability_from_math_functions_0_1_5_2.fpcore ${BINADES[@]}

pushd ${SCRIPT_LOCATION}/../cost-measurement/
python3 ${SCRIPT_LOCATION}/generate_aggregated_graph.py $(wildcard *.data)
popd
echo "<h1>Aggregated Graph</h1>" >> $date/index.html
echo "<img src='aggregate.png'>" >> $date/index.html

cat <<EOF >> $date/index.html
</body>
EOF

mv ${SCRIPT_LOCATION}/../cost-measurement/*.png $date
mv ${SCRIPT_LOCATION}/../cost-measurement/*.data $date

if [ "$(hostname)" = "warfa" ]; then
    scp -r $date uwplse.org:/var/www/fptuner/
fi
