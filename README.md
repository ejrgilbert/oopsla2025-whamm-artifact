# Whamm Artifact - OOPSLA 2025 #

_Debugging WebAssembly? Put some Whamm on it._

This is the artifact to accompany the Whamm paper published by OOPSLA 2025.
The paper presents Whamm, a framework for WebAssembly instrumentation that can instrument
via bytecode rewriting or the Whamm engine interface, named _wei_. The evaluation compares
Whamm with other frameworks in both usability and performance.

## Overview ##

This artifact includes scripts to run the experiments that compare instrumentation overheads across the following Wasm frameworks:
- [Whamm](https://github.com/ejrgilbert/whamm), rewriting
- [Whamm](https://github.com/ejrgilbert/whamm) engine interface (_wei_), implemented on [Wizard](https://github.com/titzer/wizard-engine)
- [Wasabi](http://wasabi.software-lab.org/)
- [Wirm](https://github.com/composablesys/wirm), rewriting
- [Wizard](https://github.com/titzer/wizard-engine) native instrumentation
- [Pin](https://www.intel.com/content/www/us/en/developer/articles/tool/pin-a-dynamic-binary-instrumentation-tool.html) machine code instrumentation

It also evaluates the impact of the various interpreter and JIT optimizations for _wei_ presented in the paper.

The scripts to plot the data in violin plots for evaluation are also included in `src/plot/whamm*.py`

This artifact uses the following versions for its software dependencies:
- [Rewriting-instrumenter](https://github.com/ejrgilbert/rewriting-instrumenter), sha: 2f23d7b261ec0b79809dcc57224ef06f40e8a5e2
- [V8](https://v8.dev/docs/source-code), sha: 8db16e651ff456e0eea6e576045623d2039a1d34
- [Pin](https://www.intel.com/content/www/us/en/developer/articles/tool/pin-a-dynamic-binary-instrumentation-tool.html), version 3.1
- [hyperfine](https://github.com/sharkdp/hyperfine), version 1.19.0
- [Wasabi](https://github.com/danleh/wasabi), sha: 21a322b7faac9440b931762aae124ffa57d0fa17
- [Whamm](https://github.com/ejrgilbert/whamm), sha: f7ffe1b10f68f00a5ecf5e8453bdcd53db395b4b
- [Wizeng](https://github.com/ejrgilbert/wizard-engine), sha: e4a786735d11e156f2fe32b8ad19a2e0da6fde43, the specific binary configurations built are explained in `resources/bin/wizeng/README.md`

The following provides a high-level overview of the artifact repository:
- `run.sh`: The script run by the end-user to start artifact execution (builds the Docker image and starts the container).
- `docker/`: All logic necessary to build the Docker image.
- `entrypoint.sh`: The entrypoint of the Docker container: sets up and validates the environment configuration, executes the experiments, and plots the results.
- `resources/`: All supporting files such as binaries, submodules, monitor implementations for each evaluated framework, benchmark suites, and the original data from the paper.
- `src/`: All core logic to `run/` the experiments and `plot/` the results.

## Getting Started ##

The entire artifact is run in Docker, so _getting started_ is very simple.

**Install software.** The artifact depends on the following software, we used the listed versions but the artifact will likely work with newer versions as well:
- Docker, version 27.3.1
- Git, 2.39.5

Make sure Docker runs correctly:
```bash
docker run hello-world
```

**Clone Submodules.**
```bash
git submodule init && git submodule update
```

## Run Instructions ##

```bash
# Just run it! (everything runs in docker)
./run.sh
```

> [!WARNING] The _full_ artifact will only work on an x86_64 Linux machine due to the constraints of the Pin framework.
> However, if this set of experiments is turned off using the `MONITORS` variable in `src/run/run-exp.py`, the artifact can also run on an `amd64` machine.

In order to run the artifact, the end-user simply needs to enter the base directory and run the `run.sh` script. This script performs the following actions:
1. Build the Docker image.
2. Start the Docker container (runs entrypoint.sh).
3. Sets up and validates the environment configuration.
4. Runs the experiments (runs src/run/run-exp.py).
5. Plots the results (runs src/plot/whamm*.py).

The following global variables in src/run/run-exp.pycan be modified to customize experiment execution:
- `RUNS`: The number of times to run each experiment (results are averaged across runs).
- `RUN_TIMEOUT` (seconds): How long to allow an experiment to run before timing out (some configurations can take 40 minutes to run without this timeout).
- `TOO_LONG` (seconds): If an experiment takes longer than this number of seconds, it will only be executed `RUNS_FOR_LONG` times rather than `RUNS` times.
- `RUNS_FOR_LONG`: The number of times to run if an experiment takes longer than TOO_LONG
to execute.
- `RUN_BASELINES`: Whether to run and collect the baseline data.
- `MONITORS`: The monitors to run and collect data for during this experiment execution (comment out monitors to not run).
- `EXPS`: The experiment configurations to run during this execution (comment out configurations to not run).
- `ERR_STRS`: If any of these strings are found in an experiment’s logged output, it is categorized as a failure and the output file will be saved to `out/<timestamp>/errors`.
- `SKIP`: A list of benchmarks to skip in the suite as the script is executing, put the full filename (e.g. `SKIP = [ "jacobi-1d.wasm" ]`).

### Verify Setup ###

It is recommended to do the following to validate the setup of the artifact. Doing so will result  in running end-to-end on a single benchmark by running each experiment configuration once and  timing out if a configuration runs for over 60 seconds.
1. Run end-to-end on a single benchmark. Do this by leaving a single benchmark file in resources/suites/polybench, the jacobi-1d benchmark is recommended (it is shortest).
2. Limit experiment executions by changing `src/run/run-exp.pyglobals`:
- `RUNS = 1`
- `RUN_TIMEOUT = 60`

If the artifact ran successfully, where `<timestamp>` is the time that the experiment run started (see how `entrypoint.sh` uses the date command):
- an experiment log should be written to `out/<timestamp>-output_run.log`.
- the data should be written to `out/<timestamp>/results/<timestamp>.csv`.
- the plots should be written to `out/<timestamp>/results/plots/*.pdf`.

### To Manually Parallelize (a week to run is just too long...) ###

If the above validation worked (see "Verify Setup"), a **full run** of the artifact can be performed by undoing the above modifications and running `./run.sh`.
Doing so will not overwrite any previous execution's data due to the use of _timestamps_.
A full run of the artifact with all original configurations takes over a week to run.
Rather than running for a full week, it is recommended to manually parallelize the execution.
The `RUNS`} and `RUN_TIMEOUT`} variables can also be lowered as mentioned above.
However, it is crucial to make sure that the number of parallel processes does not impact the collected results; _do not overburden your machine_.
To manually parallelize the experiment execution, collect data, and plot the results perform the following steps.

**Collect the data:**
1. _Comment out the plotting logic_} in `entrypoint.sh` found at the bottom of the script in the section starting with "Plotting the experiment results"
2. Run all experiments with _one monitor per process_.
   Uncomment a single monitor in the `MONITORS`} variable of the `src/run/run-exp.py` script, then execute `./run.sh`. 
   Make sure the `./run.sh`} execution has reached the point that it's executing `src/run/run-exp.py` before editing the `MONITORS` list for the next configuration!
3. _Collect the data_} by concatenating all `out/<timestamp>/results/<timestamp>.csv` from the above executions into a single results file.
   Place this at `out/tmp/results/tmp.csv`.
4. _Reset the artifact_} by uncommenting the plotting logic and undoing changes to `MONITORS`.

**Plot the data:**
1. _Comment out the experiment run logic_ in `entrypoint.sh` found above the plotting section, this section starts with "Running the configured experiments"
2. Point to the _collected results file_ now located at `out/tmp/results/tmp.csv`.
   Do this by overwriting the timestamp variable by adding `ts="tmp"` at the beginning of the plotting section.
3. _Run the artifact_ with `./run.sh`.
4. _Reset the artifact_ by undoing the changes made to `entrypoint.sh`.

## How to Extend ##

This artifact can be extended to support more benchmark suites and monitors. Unfortunately, the
plotting scripts have not been written with extensibility in mind. If plots are needed after extending
the artifact, the plotting scripts will need to be manually adapted.
 
### Adding a new suite. ###
1. Add a new folder with the benchmark suite name to `resources/suites`.
2. Point to that new suite by putting the same name as the directory in the `SUITES` variable in the `src/run/run-exp.py script`.
   Running `./run.sh` should now pick up the new suite of benchmarks.
   To support running the Pin experiment configuration, the benchmarks will need to be available as machine code and Wasm modules, instructions to generate machine code from Wasm code is available in `src/pin-utils/README.md` (follow the same structure as used by the `polybench-mach` suite already configured).

### Adding a new monitor. ###
1. New monitors should be placed in `resources/monitors` for the corresponding framework(s).
2. Modify the `MONITORS` variable in the `src/run/run-exp.py` script to include the new monitor in the list. The name of the dictionary key should match the name of the monitor’s file (without the file extension). The value of the dictionary is used for configuring libraries (only relevant for Whamm monitors).
3. If the new monitor is for a specific framework, comment out other framework experiment
configurations in the `EXPS` variable of the `src/run/run-exp.py` script.
