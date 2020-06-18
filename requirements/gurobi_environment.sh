
# This can be used if:
#   * gurobi version is 902
#   * gurobi was untarred in requirements
#   * the liscence key is in HOME
#   * the python version used is 3.6

if [ "${SHELL}" = "zsh" ]
then
  SCRIPT_DIR="$( cd "$( dirname "${0}" )" && pwd )"
else # assumed to be bash
  SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
fi

GUROBI_HOME="${SCRIPT_DIR}/gurobi902/linux64"
export GRB_LICENSE_FILE="${HOME}/gurobi.lic"
export PATH="${GUROBI_HOME}/bin:${PATH}"
export LD_LIBRARY_PATH="${GUROBI_HOME}/lib:${LD_LIBRARY_PATH}"
export PYTHONPATH="${GUROBI_HOME}/lib/python3.6_utf32:${PYTHONPATH}"
