#!/bin/bash

PIN_DIR=~/pin/
RUNS=1

for exe in exes/*; do
        name=$(basename "$exe")
        out="results/${name}"
        
        tests=("$exe" "$PIN_DIR/pin -- $exe")
        for pintool in pintools/*.so; do
            basename=$(basename "$pintool")

            if [[ "$basename" == "dcache.so" ]]; then
                tests+=("$PIN_DIR/pin -t $pintool -c 1024 -d 256 -- $exe")
	    else
                tests+=("$PIN_DIR/pin -t $pintool -- $exe")
	    fi
        done
        
	hyperfine -r $RUNS --export-csv "${out}.csv" "${tests[@]}"
done

rm *.out
