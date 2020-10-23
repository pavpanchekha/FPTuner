#!/bin/bash

set -e -x

SCRIPT_LOCATION=$(readlink -f $(dirname $0))

rm -rf ${SCRIPT_LOCATION}/../cost-measurement/kerns

date=$(date +%s)

FPTUNER="${SCRIPT_LOCATION}/fptuner --nightly --cfile"


run ()
{
    \time -f %e ${FPTUNER} ${SCRIPT_LOCATION}/../benchmarks/check_benchmarks/$1 -e ${@:2} -v low | tee -a $date/index.html
    echo -e "\n\n\n\n"
}

mkdir $date
cat <<EOF > $date/index.html
<!doctype html>
<title>FPTuner Results for $(date +%Y-%m-%d)</title>
<body>
EOF

DECIMATION=( 1e2 1e1 1e0 1e-1 1e-2 1e-3 1e-4 1e-5 1e-6 1e-7 1e-8 1e-9 1e-10 1e-11 1e-12 1e-13 1e-14 )

run azimuth.fpcore ${DECIMATION[@]}
run complex_sine_and_cosine.fpcore ${DECIMATION[@]}
run Data_HyperLogLog_Type_size_from_hyperloglog_0_3_4_A.fpcore ${DECIMATION[@]}
run Data_Number_Erf_dmerfcx_from_erf_2_0_0_0.fpcore ${DECIMATION[@]}
run Data_Random_Distribution_Normal_normalF_from_random_fu_0_2_6_2.fpcore ${DECIMATION[@]}
run Diagrams_ThreeD_Transform_aboutX_from_diagrams_lib_1_3_0_3_A.fpcore ${DECIMATION[@]}
run Diagrams_ThreeD_Transform_aboutX_from_diagrams_lib_1_3_0_3_B.fpcore ${DECIMATION[@]}
run Diagrams_ThreeD_Transform_aboutY_from_diagrams_lib_1_3_0_3.fpcore ${DECIMATION[@]}
run Diagrams_TwoD_Path_Metafont_Internal_hobbyF_from_diagrams_contrib_1_3_0_5.fpcore ${DECIMATION[@]}
run exp1x_32.fpcore ${DECIMATION[@]}
run exp1x.fpcore ${DECIMATION[@]}
run exp1x_log.fpcore ${DECIMATION[@]}
run hartman3.fpcore ${DECIMATION[@]}
# run hartman6.fpcore ${DECIMATION[@]}
run i6.fpcore ${DECIMATION[@]}
run Linear_Quaternion_cexp_from_linear_1_19_1_3.fpcore ${DECIMATION[@]}
run logexp2.fpcore ${DECIMATION[@]}
run logexp.fpcore ${DECIMATION[@]}
run nmse_example_3_10.fpcore ${DECIMATION[@]}
run nmse_example_3_3.fpcore ${DECIMATION[@]}
run nmse_example_3_4.fpcore ${DECIMATION[@]}
run nmse_example_3_7.fpcore ${DECIMATION[@]}
run nmse_example_3_8.fpcore ${DECIMATION[@]}
run nmse_problem_3_3_2.fpcore ${DECIMATION[@]}
run nmse_problem_3_3_6.fpcore ${DECIMATION[@]}
run nmse_problem_3_3_7.fpcore ${DECIMATION[@]}
run nmse_problem_3_4_2.fpcore ${DECIMATION[@]}
run nmse_problem_3_4_4.fpcore ${DECIMATION[@]}
run nmse_section_3_11.fpcore ${DECIMATION[@]}
run nmse_section_3_5.fpcore ${DECIMATION[@]}
run Numeric_SpecFunctions_invIncompleteBetaWorker_from_math_functions_0_1_5_2_B.fpcore ${DECIMATION[@]}
run Numeric_SpecFunctions_logBeta_from_math_functions_0_1_5_2_A.fpcore ${DECIMATION[@]}
run Numeric_SpecFunctions_logBeta_from_math_functions_0_1_5_2_B.fpcore ${DECIMATION[@]}
run Numeric_SpecFunctions_logGammaL_from_math_functions_0_1_5_2.fpcore ${DECIMATION[@]}
run Numeric_SpecFunctions_slogFactorial_from_math_functions_0_1_5_2_B.fpcore ${DECIMATION[@]}
run Numeric_SpecFunctions_stirlingError_from_math_functions_0_1_5_2.fpcore ${DECIMATION[@]}
run sphere.fpcore ${DECIMATION[@]}
run Statistics_Distribution_Beta_cdensity_from_math_functions_0_1_5_2.fpcore ${DECIMATION[@]}
run Statistics_Distribution_Binomial_directEntropy_from_math_functions_0_1_5_2.fpcore ${DECIMATION[@]}
run Statistics_Distribution_Poisson_clogProbability_from_math_functions_0_1_5_2.fpcore ${DECIMATION[@]}
run Statistics_Distribution_Poisson_Internal_probability_from_math_functions_0_1_5_2.fpcore ${DECIMATION[@]}

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
