#!/bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE"  ]; do
    DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /*  ]] && SOURCE="$DIR/$SOURCE"
done
DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"

. "$DIR/docker/utils.sh"

IMG_NAME="whamm-eval"
MNT_NAME="/eval"

# Detect if running on AMD
if lscpu | grep "Vendor ID" | grep -q "AuthenticAMD"; then
    echo "AMD CPU detected"
else
    echo "Not an AMD CPU"
fi

# Build the docker image
pushd ./docker >/dev/null || error_exit "could not cd into './docker'"
# docker build --progress=plain --no-cache --tag $IMG_NAME ./ # TODO (while debugging) -- switch to below command after ready!
if ! docker build --platform=linux/amd64 --tag $IMG_NAME ./; then
    echo "Something went wrong while building the docker container"
    exit 1
fi

popd >/dev/null || error_exit "could not popd from './docker'"

echo
echo

# Run the docker image (will implicitly run the experiments)
if docker run --platform=linux/amd64 -u "$(stat -f "%u:%g" "$PWD")" -v "$PWD":$MNT_NAME $IMG_NAME "$@"; then
    echo
    log_ok "Completed running the experiments, please see output at 'out/'"
else
    echo
    log_fail "Running the experiments failed, please check for errors."
fi
