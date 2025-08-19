#!/bin/bash

TEMPLATE_FILE="template.c.h"
NOTHING_FILE="nothing.c.h"

CC=gcc
CFLAGS=-O2
RUNTIME_DIR="/usr/src/wasm2c/"

BENCHMARK_DIR="../suites/r3/"
OUTPUT_DIR="exes/"

for file in $BENCHMARK_DIR/*.wasm; do
 (
    name=${file##*/}
    name=${name%.wasm}
    name=${name//-/}

    [ -e "$file" ] || continue
    
    wasm2c "$file" -o "$name.c" --module-name=$name

    # generate main
    sed "s/TEMPLATE/$name/g" "$TEMPLATE_FILE" > "${name}_main.c"
    sed "s/TEMPLATE/$name/g" "$NOTHING_FILE" > "${name}_main_nothing.c"

    # compile
    $CC $CFLAGS -o "$OUTPUT_DIR/$name" ${name}_main.c $name.c $RUNTIME_DIR/wasm-rt-impl.c -lm
    $CC $CFLAGS -o "$OUTPUT_DIR/${name}_ret0" ${name}_main_nothing.c $name.c $RUNTIME_DIR/wasm-rt-impl.c -lm

    # delete
    rm $name.c $name.h ${name}_main.c ${name}_main_nothing.c
 ) &
done

wait

