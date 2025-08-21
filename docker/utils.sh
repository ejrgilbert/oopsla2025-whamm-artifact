export V8_SHA="8db16e651ff456e0eea6e576045623d2039a1d34"

export RUST_VERSION="1.85.1"

export PATH=/depot_tools:$PATH

export DIR_BASE="/eval"
export DIR_RSC="${DIR_BASE}/resources"
export DIR_BIN="${DIR_RSC}/bin"
export DIR_SRC="${DIR_BASE}/src"
export DIR_OUT="${DIR_BASE}/out"

# Logging functions
log_ok() {
  GREEN_COLOR="\033[0;32m"
  DEFAULT="\033[0m"
  echo -e "${GREEN_COLOR} ✔ [OK] ${1:-} ${DEFAULT}"
}

log_warning() {
  YELLOW_COLOR="\033[33m"
  DEFAULT="\033[0m"
  echo -e "${YELLOW_COLOR} ⚠ ${1:-} ${DEFAULT}"
}

log_info() {
  BLUE_COLOR="\033[0;34m"
  DEFAULT="\033[0m"
  echo -e "${BLUE_COLOR} ℹ ${1:-} ${DEFAULT}"
}

log_fail() {
  RED_COLOR="\033[0;31m"
  DEFAULT="\033[0m"
  echo -e "${RED_COLOR} ❌ ${1:-}${DEFAULT}"
}

function error_exit() {
  log_fail "$*"
  exit 1
}
