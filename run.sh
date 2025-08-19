#!/bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE"  ]; do
    DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /*  ]] && SOURCE="$DIR/$SOURCE"
done
DIR="$( cd -P "$( dirname "$SOURCE"  )" >/dev/null 2>&1 && pwd  )"

IMG_NAME="whamm-eval"
MNT_NAME="/eval"

# Build the docker image
pushd ./docker >/dev/null
# docker build --progress=plain --no-cache --tag $IMG_NAME ./ # TODO (while debugging) -- switch to below command after ready!
if ! docker build --tag $IMG_NAME ./; then
    echo "Something went wrong while building the docker container"
    exit 1
fi

popd >/dev/null

# Run the docker image (will implicitly run the experiments)
if docker run -u `stat -c "%u:%g" $PWD` -v "$PWD":$MNT_NAME $IMG_NAME "$@"; then
    log_ok "Completed running the experiments, please see output at 'output/'"
else
    log_fail "Running the experiments failed, please check for errors."
fi
