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

# Detect if running on a Mac
if uname -m | grep "arm" >/dev/null; then
    arm_arg="--platform=linux/amd64"
    user_opt="-f"
else
    user_opt='--printf'
fi

# Build the docker image
pushd ./docker >/dev/null || error_exit "could not cd into './docker'"
# docker build --progress=plain --no-cache --tag $IMG_NAME ./ # TODO (while debugging) -- switch to below command after ready!
if ! docker build "${arm_arg}" --tag $IMG_NAME ./; then
    echo "Something went wrong while building the docker container"
    exit 1
fi

popd >/dev/null || error_exit "could not popd from './docker'"

echo
echo

# Run the docker image (will implicitly run the experiments)
if docker run "${arm_arg}" -u "$(stat ${user_opt} "%u:%g" "$DIR")" -v "$PWD":$MNT_NAME $IMG_NAME "$@"; then
    echo
    log_ok "Completed running the experiments, please see output at 'out/'"
else
    echo
    log_fail "Running the experiments failed, please check for errors."
fi
