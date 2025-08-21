#!/bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE"  ]; do
    DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /*  ]] && SOURCE="$DIR/$SOURCE"
done
DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"

. "$DIR/docker/utils.sh"

echo "=========================================="
log_info "Setting up and verifying dependencies."

#log_info "[hyperfine] Verifying the setup."
#if ! "${DIR_BIN}"/hyperfine-v1.19.0-x86_64-unknown-linux-gnu/hyperfine --version; then
#    error_exit "hyperfine is not set up correctly."
#fi
#
#log_info "[depot-tools] Verifying the setup."
#if ! gclient --version; then
#    error_exit "depot-tools is not set up correctly."
#fi
#
#log_info "[python] Verifying the setup."
#if ! python3 --version; then
#    error_exit "Python is not set up correctly."
#fi
#
#log_info "[cargo] Setting up Rust."
#
#curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | bash -s -- -y || exit 1
#. "$HOME/.cargo/env"
#rustup install "${RUST_VERSION}" || error_exit "rustup not installed correctly."
#rustup default "${RUST_VERSION}"
#rustup target add wasm32-wasip1
#
#log_info "[cargo] Verifying setup."
#if ! cargo --version; then
#    error_exit "Cargo is not set up correctly."
#fi
#
#log_info "[rewriting] Setting up the rewriting-instrumenter."
#pushd "${DIR_BIN}"/rewriting-instrumenter >/dev/null || error_exit "could not pushd"
#cargo build --release
#popd >/dev/null || error_exit "could not popd"
#
#log_info "[rewriting] Verifying setup."
#if [[ $("${DIR_BIN}"/rewriting-instrumenter/target/release/rewriting_monitor 2>&1) != *"Usage"* ]]; then
#    error_exit "Rewriting instrumenter is not set up correctly."
#fi
#
#log_info "[v8] Setting up."
#
#log_info "[v8] Verifying setup."
#if ! "${DIR_BIN}"/v8/out/x64.release/d8 --version; then
#    error_exit "v8 is not set up correctly."
#fi
#
#log_info "[wasabi] Verifying setup."
#if ! "${DIR_BIN}"/wasabi/wasabi --help; then
#    error_exit "Wasabi is not set up correctly."
#fi
#
#pushd "${DIR_BIN}"/whamm >/dev/null || error_exit "could not pushd"
#
#log_info "[whamm] Building whamm_core."
#pushd ./whamm_core >/dev/null || error_exit "could not pushd"
#cargo build --release --target wasm32-wasip1
#popd >/dev/null || error_exit "could not popd"
#
#log_info "[whamm] Building whamm."
#cargo build --release
#popd >/dev/null || error_exit "could not popd"
#
#log_info "[whamm] Verifying whamm."
#if ! "${DIR_BIN}"/whamm/target/release/whamm --help; then
#    error_exit "Whamm is not set up correctly."
#fi
#
#log_info "[whamm] Verifying whamm_core."
#if ! ls "${DIR_BIN}"/whamm/whamm_core/target/wasm32-wasip1/release/whamm_core.wasm --help; then
#    error_exit "Could not find build whamm_core wasm module."
#fi
#
#log_info "[wizeng] Verifying wizard engine setup."
#for wizeng in "${DIR_BIN}"/wizeng/wizeng*; do
#    if ! $wizeng --help; then
#        error_exit "Wizard engine build is not set up correctly for: ${wizeng}"
#    fi
#done
#
#log_info "[pin] Setting up Pin."
#
## TODO: setup `pin`
#
#log_info "[cargo] Verifying Pin setup."
#
## TODO: validate setup `pin`


echo "=========================================="
log_info "Running the configured experiments."

run_out="${DIR_OUT}/output_run.log"
if ! python3 "${DIR_SRC}"/run/run-exp.py 2>&1 | tee "${run_out}"; then
    error_exit "'python3 ${DIR_SRC}/run/run-exp.py' failed."
fi

echo "=========================================="
log_info "Plotting the experiment results."

# TODO
