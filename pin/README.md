# Evaluation of overhead of Pin

## compile benchmarks with `wasm2c`

You will need `wasm2c` for this step.

* `wasm2c.sh`: compiles wasm benchmarks that don't require WASI to native code
  and adds them to `exes/`. Right now it's just the `r3` suite.
* `wasm2c_wasi.sh`: compiles wasm benchmarks with WASI, using stubs for all the
  WASI functions. You will need to preface this script with the directory of the
  benchmarks:
  - `BENCHMARK_DIR="../suites/libsodium" ./wasm2c_wasi.sh` (there seems to be
    some very long running benchmarks in this folder)
  - `BENCHMARK_DIR="../suites/ostrich" ./wasm2c_wasi.sh`
  - `BENCHMARK_DIR="../suites/polybench" ./wasm2c_wasi.sh`

You will need `wasm-rt-impl.c` which should also be available in the wasm2c
source directory (this is specified by `RUNTIME_DIR` in both scripts). I can't
seem to find the files installed on gargantua so I may have to provide it
directly.

This compiles two executables: a normal one that performs the benchmark and one 
where the main function immediately returns 0 (to test some base overhead). 
The `return 0` benchmark has `_ret0` appended to the name.

## make pintools

You will need [pin](https://www.intel.com/content/www/us/en/developer/articles/tool/pin-a-binary-instrumentation-tool-downloads.html)
installed.

`make_pintools.sh` compiles a selection of pintools and adds them to
`pintools/`. Make sure `PIN_DIR` in the script is set to the directory of the
installation and that `TARGET` is correct.

## run benchmarks

`benchmark.sh` runs every executable in `exes/` with all the pintools with
`pintools/`. It also measures the base time to run the program and time to run
it with pin without a pintool. The result of this is stored as a `.csv` in
`results/`.

You can customize the number of runs with `RUNS` in the script.

`benchmark_par.sh` can run these benchmarks in parallel (constrained by the
maximum number of jobs in `MAX_JOBS`) but I have found this to make the
benchmark times more wonky than comfortable.
