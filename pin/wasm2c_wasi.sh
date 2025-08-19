#!/bin/bash

TEMPLATE_FILE="template_wasi.c.h"
NOTHING_FILE="nothing_wasi.c.h"

CC=gcc
CFLAGS=-O2
RUNTIME_DIR="/usr/src/wasm2c/"

#BENCHMARK_DIR="../suites/ostrich/"
OUTPUT_DIR="exes/"

for file in $BENCHMARK_DIR/*.wasm; do
 (
    name=${file##*/}
    name=${name%.wasm}
    name=${name//-/}
    name=${name//_/}
    # rename 2mm and 3mm
    if [[ $name =~ ^[0-9] ]]; then
        name="${name:1}${name:0:1}"
    fi

    [ -e "$file" ] || continue
    
    wasm2c "$file" -o "$name.c" --module-name=$name

    # generate main
    sed "s/TEMPLATE/$name/g" "$TEMPLATE_FILE" > "${name}_main.c"
    sed "s/TEMPLATE/$name/g" "$NOTHING_FILE" > "${name}_main_nothing.c"

    # compile
    $CC $CFLAGS -o "$OUTPUT_DIR/$name" ${name}_main.c $name.c $RUNTIME_DIR/wasm-rt-impl.c wasm-wasi-stubs.c -lm
    $CC $CFLAGS -o "$OUTPUT_DIR/${name}_ret0" ${name}_main_nothing.c $name.c $RUNTIME_DIR/wasm-rt-impl.c wasm-wasi-stubs.c -lm

    # delete
    rm $name.c $name.h ${name}_main.c ${name}_main_nothing.c
 ) &
done

wait

