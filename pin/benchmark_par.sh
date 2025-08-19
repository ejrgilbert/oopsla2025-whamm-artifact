#!/bin/bash

PIN_DIR=~/pin/
RUNS=10

MAX_JOBS=27
running=0  

for exe in exes/*; do
  while [ "$running" -ge "$MAX_JOBS" ]; do  
    wait -n  
    ((running--))  
  done  

  (  
        name=$(basename "$exe")
        out="results/${name}"

        tests=("$exe" "$PIN_DIR/pin -- $exe")
        for pintool in pintools/*.so; do
            if [[ "$basename" == "dcache.so" ]]; then
                tests+=("$PIN_DIR/pin -t $pintool -c 1024 -b 256 -- $exe")
	    else
                tests+=("$PIN_DIR/pin -t $pintool -- $exe")
	    fi
        done

	hyperfine -r $RUNS --export-csv "${out}.csv" "${tests[@]}" &>/dev/null
	echo $name
  ) &  

  ((running++))  
done  

wait
rm *.out

