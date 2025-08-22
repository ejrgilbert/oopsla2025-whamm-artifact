#!/bin/bash

TEMPLATE_FILE="template.c.h"

CC=gcc
OPT=-O3
RUNTIME_DIR="/usr/src/wasm2c/"

BENCHMARK_DIR="../suites/r3"
OUTPUT_DIR="exes/"

for file in $BENCHMARK_DIR/*.wasm; do
    name=${file##*/}
    name=${name%.wasm}

    echo $name

    [ -e "$file" ] || continue
    
    wasm2c "$file" -o "module.c" --module-name=module

    # generate main
    sed "s/TEMPLATE/module/g" "$TEMPLATE_FILE" > "main.c"

    # compile
    $CC $OPT -o "$OUTPUT_DIR/$name" main.c module.c $RUNTIME_DIR/wasm-rt-impl.c -lm

    # delete
    rm main.c module.h module.c
done

