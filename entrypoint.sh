#!/bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE"  ]; do
    DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /*  ]] && SOURCE="$DIR/$SOURCE"
done
DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"

. "$DIR/docker/utils.sh"

echo "====================================="
log_info "Verifying setup of dependencies."

log_info "[python] Verifying the setup."
if ! python3 --version; then
    error_exit "Python is not set up correctly."
fi

log_info "[cargo] Setting up Rust."

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | bash -s -- -y || exit 1
. "$HOME/.cargo/env"
rustup install 1.85.1 || error_exit "rustup not installed correctly."

if ! cargo --version; then
    error_exit "Cargo is not set up correctly."
fi

# TODO: setup `rewriting-instrumenter`
# TODO: validate setup `rewriting-instrumenter`

# TODO: setup `v8`
# TODO: validate setup `v8`

# TODO: validate setup `wasabi`

# TODO: setup `whamm`
# TODO: validate setup `whamm`

# TODO: validate setup `wizeng`

# TODO: setup `pin`
# TODO: validate setup `pin`


echo "====================================="
log_info "Running the configured experiments."
# TODO
