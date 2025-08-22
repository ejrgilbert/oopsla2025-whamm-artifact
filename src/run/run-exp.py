import csv
# import datetime
from enum import Enum
import os
import re
import shutil
from statistics import fmean
import subprocess
import uuid
from pathlib import Path
import sys

class RunMode(Enum):
    IntRtInt = "int-rt-int"
    JitRtInt = "jit-rt-int"

    IntRtJit = "int-rt-jit"
    JitRtJit = "jit-rt-jit"

    IntTrampInt = "int-tramp-int"
    JitTrampInt = "jit-tramp-int"

    IntTrampJit = "int-tramp-jit"
    JitTrampJit = "jit-tramp-jit"

    IntWasmInt = "int-wasm-int"
    JitWasmInt = "jit-wasm-int"

    IntWasmJit = "int-wasm-jit"
    JitWasmJit = "jit-wasm-jit"

    Inline = "inline"

    IntDefault = "int-default"
    JitDefault = "jit-default"

    # For Wasabi:
    V8 = "v8"
    V8Prod = "v8-prod"

    # For Pin:
    Pin = "pin"

    def __str__(self):
        return self.value
    def invocation(self):
        if self.value == "inline":
            return self.value
        return self.value.split("-", 1)[1]
    def wizeng_bin(self):
        return os.path.join(WIZ_PATH, f"wizeng.x86-64-linux_{self.invocation()}")
    def should_jit(self):
        return self.value.startswith("jit-") or self.value == "inline"

# RUNS = 5
TOO_LONG = 60
RUNS_FOR_LONG = 3
# RUN_TIMEOUT = 60 * 10 # 10 mins per run
RUN_BASELINES = True

# TODO: put this back (used to make faster)
RUNS = 1
RUN_TIMEOUT = 60 * 2 # 2 mins per run

SUITES = [ 'polybench' ]
mypath = os.path.abspath(os.path.dirname(__file__))
RSC = "../../resources"
whamm_mons = f"{RSC}/monitors/whamm/"
whamm_utils = f"{whamm_mons}/utils/"
MONITORS= {
    'branches': "",
    'hotness': "",
    'icount': "",
    'imix': "",
    'cache-sim': f"cache={mypath}/{whamm_utils}/cache.wasm",

    'mem-access': f"(whamm_hw)mem={mypath}/{whamm_utils}/mem.wasm",
    'loop-tracer': f"tracer={mypath}/{whamm_utils}/tracer.wasm",
    'basic-blocks': "",
    'instr-coverage': "",
    'call-graph': f"(whamm_hw)call={mypath}/{whamm_utils}/call.wasm"
}
# Map the name of the monitor to its corresponding pintool. Benchmarks on
# monitors that do not have the corresponding pintool are skipped.
PINTOOLS = {
    'icount': 'inscount0.so',
    'imix': 'catmix.so',
    'cache-sim': 'dcache.so',
    'mem-access': 'pinatrace.so',
}
EXPS = {
#     'whamm_engine': [
#         RunMode.IntRtInt,
#         RunMode.JitRtInt,
#         RunMode.IntRtJit,
#         RunMode.JitRtJit,
# 
#         RunMode.IntTrampInt,
#         RunMode.IntTrampJit,
# 
#         RunMode.JitWasmInt,
#         RunMode.JitWasmJit,
# 
#         RunMode.Inline,
#     ],
#     'whamm_rewrite': [
#         RunMode.IntDefault,
#         RunMode.JitDefault,
#     ],
#     'whamm_hw': [
#         RunMode.IntRtInt,
#         RunMode.JitRtInt,
#         RunMode.IntRtJit,
#         RunMode.JitRtJit,
# 
#         RunMode.IntTrampInt,
#         RunMode.IntTrampJit,
# 
#         RunMode.JitWasmInt,
#         RunMode.JitWasmJit,
# 
#         RunMode.Inline,
#     ],
#     'wizard_native': [
#         RunMode.IntDefault,
#         RunMode.JitDefault
#     ],
#     'orca_rewrite': [
#         RunMode.IntDefault,
#         RunMode.JitDefault,
#     ],
#     'wasabi': [
#         RunMode.V8,
#         RunMode.V8Prod
#     ],
    'pin': [
        RunMode.Pin
    ]
}

ERR_STRS = [ 'error', 'exception', 'trap', 'heapoverflow' ]
SKIP = []

# General setup
if len(sys.argv) != 2:
    print("Usage: run-exp.py <timestamp>\n\t<timestamp> is used to generate a unique output directory")
    sys.exit(1)
ct = sys.argv[1]
# ct = datetime.datetime.now().strftime("%Y-%m-%d--%H:%M:%S")

RSC = "../../resources"
BIN = f"{RSC}/bin"
HYPERFINE_BIN = os.path.join(mypath, f"{BIN}/hyperfine-v1.19.0-x86_64-unknown-linux-gnu/hyperfine")
WIZ_PATH = os.path.join(mypath, f"{BIN}/wizeng/")
BENCHMARK_DIR = os.path.join(mypath, f"{RSC}/suites/")

# V8 setup
D8 = os.path.join(mypath, f"{BIN}/v8/out/x64.release/d8")

# Whamm setup
WHAMM_BIN = os.path.join(mypath, f"{BIN}/whamm/target/release/whamm")
WHAMM_MM_PATH = os.path.join(mypath, f"{whamm_mons}/dsl/")
WHAMM_HW_PATH = os.path.join(mypath, f"{whamm_mons}/hw/")
CORE_LIB = os.path.join(mypath, f"{whamm_utils}/whamm_core.wasm")

# Orca setup
WIRM_REWRITER = os.path.join(mypath, f"{BIN}/rewriting-instrumenter/target/release/rewriting_monitor")

# Wasabi setup
WASABI = os.path.join(mypath, f"{BIN}/wasabi/wasabi")
WASABI_RUNNER = os.path.join(mypath, f"{BIN}/wasabi/run.js")
WASABI_MON_PATH = os.path.join(mypath, f"{RSC}/monitors/wasabi/")

# Ouktput setup
OUT = "../../out"
COMPOUT = os.path.join(mypath, f"{OUT}/{ct}/compilations")
ERROUT = os.path.join(mypath, f"{OUT}/{ct}/errors")
OUTDIR = os.path.join(mypath, f"{OUT}/{ct}/results")
OUTFILE = os.path.join(mypath, f"{OUT}/{ct}/results/{ct}.csv")

# Pin setup
PIN_BIN = os.path.join(mypath, f"{BIN}/pin-external-3.31-98869-gfa6f126a8-gcc-linux/pin")
PINTOOL_DIR = os.path.join(mypath, f"{RSC}/monitors/pin/")

class Result:
    def __init__(self,
            config_run_mode, config_monitor, config_experiment, config_special,
            benchmark_suite, benchmark_name
    ):
        self.config_run_mode = config_run_mode
        self.config_monitor = config_monitor
        self.config_experiment = config_experiment
        self.config_special = config_special

        self.benchmark_suite = benchmark_suite
        self.benchmark_name = benchmark_name
        self.has_wizeng_metrics = False
        self.run_errored = False
        self.run_timed_out = False
    
    def reset(self):
        try:
            self.run_command = ""
        except:
            pass
        try:
            self.run_outfile = ""
        except:
            pass
        try:
            self.run_time_mean[:] = []
        except:
            pass
        try:
            self.run_time_stddev[:] = []
        except:
            pass
        try:
            self.run_time_median[:] = []
        except:
            pass
        try:
            self.run_time_user[:] = []
        except:
            pass
        try:
            self.run_time_system[:] = []
        except:
            pass
        try:
            self.run_time_min[:] = []
        except:
            pass
        try:
            self.run_time_max[:] = []
        except:
            pass
        try:
            self.wiz_metrics_pregen_time_us[:] = []
        except:
            pass
        try:
            self.wiz_metrics_pregen_bytes[:] = []
        except:
            pass
        try:
            self.wiz_metrics_load_time_us[:] = []
        except:
            pass
        try:
            self.wiz_metrics_load_bytes[:] = []
        except:
            pass
        try:
            self.wiz_metrics_load_time_per_byte[:] = []
        except:
            pass
        try:
            self.wiz_metrics_validate_time_us[:] = []
        except:
            pass
        try:
            self.wiz_metrics_validate_bytes[:] = []
        except:
            pass
        try:
            self.wiz_metrics_validate_time_per_byte[:] = []
        except:
            pass
        try:
            self.wiz_metrics_spc_in_bytes[:] = []
        except:
            pass
        try:
            self.wiz_metrics_spc_code_bytes[:] = []
        except:
            pass
        try:
            self.wiz_metrics_spc_data_bytes[:] = []
        except:
            pass
        try:
            self.wiz_metrics_spc_time_us[:] = []
        except:
            pass
        try:
            self.wiz_metrics_spc_functions[:] = []
        except:
            pass
        try:
            self.wiz_metrics_spc_time_per_byte[:] = []
        except:
            pass
        try:
            self.wiz_metrics_start_time_us[:] = []
        except:
            pass
        try:
            self.wiz_metrics_main_time_us[:] = []
        except:
            pass
        try:
            self.wiz_metrics_main_time_cycles[:] = []
        except:
            pass
        try:
            self.wiz_metrics_probes_fired[:] = []
        except:
            pass
        try:
            self.wiz_metrics_whamm_bind_time_us[:] = []
        except:
            pass
        try:
            self.wiz_metrics_whamm_report_time_us[:] = []
        except:
            pass
        self.has_wizeng_metrics = False
        self.run_errored = False
        self.run_timed_out = False

    def set_outfile(self,run_errored, run_outfile):
        try:
            self.run_errored |= run_errored
        except AttributeError:
            self.run_errored = run_errored
        self.run_outfile = run_outfile

    def timed_out_res(self,run_errored,run_timed_out,run_outfile):
        self.set_outfile(run_errored, run_outfile)
        try:
            self.run_timed_out |= run_timed_out
        except AttributeError:
            self.run_timed_out = run_timed_out

    def run_res(self,
        run_errored,run_timed_out,run_command,run_outfile,run_time_mean,run_time_stddev,run_time_median,run_time_user,run_time_system,run_time_min,run_time_max,
    ):
        self.timed_out_res(run_errored,run_timed_out, run_outfile)
        self.run_command = run_command
        try:
            self.run_time_mean.append(run_time_mean)
        except AttributeError:
            self.run_time_mean = [run_time_mean]
        try:
            self.run_time_stddev.append(run_time_stddev)
        except AttributeError:
            self.run_time_stddev = [run_time_stddev]
        try:
            self.run_time_median.append(run_time_median)
        except AttributeError:
            self.run_time_median = [run_time_median]
        try:
            self.run_time_user.append(run_time_user)
        except AttributeError:
            self.run_time_user = [run_time_user]
        try:
            self.run_time_system.append(run_time_system)
        except AttributeError:
            self.run_time_system = [run_time_system]
        try:
            self.run_time_min.append(run_time_min)
        except AttributeError:
            self.run_time_min = [run_time_min]
        try:
            self.run_time_max.append(run_time_max)
        except AttributeError:
            self.run_time_max = [run_time_max]

    def wiz_metrics(self,
        metrics_str
    ):
        self.has_wizeng_metrics = True;
        for line in metrics_str.splitlines():
            if line.startswith("pregen:time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_pregen_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_pregen_time_us = [val]
            elif line.startswith("pregen:bytes"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_pregen_bytes.append(val)
                except AttributeError:
                    self.wiz_metrics_pregen_bytes = [val]
            elif line.startswith("load:time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_load_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_load_time_us = [val]
            elif line.startswith("load:bytes"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_load_bytes.append(val)
                except AttributeError:
                    self.wiz_metrics_load_bytes = [val]
            elif line.startswith("load:time_per_byte"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_load_time_per_byte.append(val)
                except AttributeError:
                    self.wiz_metrics_load_time_per_byte = [val]
            elif line.startswith("validate:time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_validate_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_validate_time_us = [val]
            elif line.startswith("validate:bytes"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_validate_bytes.append(val)
                except AttributeError:
                    self.wiz_metrics_validate_bytes = [val]
            elif line.startswith("validate:time_per_byte"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_validate_time_per_byte.append(val)
                except AttributeError:
                    self.wiz_metrics_validate_time_per_byte = [val]
            elif line.startswith("spc:in_bytes"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_spc_in_bytes.append(val)
                except AttributeError:
                    self.wiz_metrics_spc_in_bytes = [val]
            elif line.startswith("spc:code_bytes"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_spc_code_bytes.append(val)
                except AttributeError:
                    self.wiz_metrics_spc_code_bytes = [val]
            elif line.startswith("spc:data_bytes"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_spc_data_bytes.append(val)
                except AttributeError:
                    self.wiz_metrics_spc_data_bytes = [val]
            elif line.startswith("spc:time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_spc_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_spc_time_us = [val]
            elif line.startswith("spc:functions"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_spc_functions.append(val)
                except AttributeError:
                    self.wiz_metrics_spc_functions = [val]
            elif line.startswith("spc:time_per_byte"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_spc_time_per_byte.append(val)
                except AttributeError:
                    self.wiz_metrics_spc_time_per_byte = [val]
            elif line.startswith("start:time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_start_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_start_time_us = [val]
            elif line.startswith("main:time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_main_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_main_time_us = [val]
            elif line.startswith("main:time_cycles"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_main_time_cycles.append(val)
                except AttributeError:
                    self.wiz_metrics_main_time_cycles = [val]
            elif line.startswith("probes:fired"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_probes_fired.append(val)
                except AttributeError:
                    self.wiz_metrics_probes_fired = [val]
            elif line.startswith("whamm:bind_time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_whamm_bind_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_whamm_bind_time_us = [val]
            elif line.startswith("whamm:report_time_us"):
                val = extract_num(line)
                try:
                    self.wiz_metrics_whamm_report_time_us.append(val)
                except AttributeError:
                    self.wiz_metrics_whamm_report_time_us = [val]
            else:
                continue

    def hdr():
        return ('config:run_mode,config:monitor,config:experiment,config:special,'
         'benchmark:suite,benchmark:name,'
         'run_errored,run_outfile,run_timed_out,run_time:mean,run_time:user,run_time:system,'
         'wiz_metrics_pregen:time_us,wiz_metrics_pregen:bytes,wiz_metrics_load:time_us,wiz_metrics_load:bytes,wiz_metrics_load:time_per_byte,'
         'wiz_metrics_validate:time_us,wiz_metrics_validate:bytes,wiz_metrics_validate:time_per_byte,'
         'wiz_metrics_spc:in_bytes,wiz_metrics_spc:code_bytes,wiz_metrics_spc:data_bytes,wiz_metrics_spc:time_us,wiz_metrics_spc:functions,wiz_metrics_spc:time_per_byte,'
         'wiz_metrics_start:time_us,wiz_metrics_main:time_us,wiz_metrics_main:time_cycles,'
         'wiz_metrics_probes:fired,wiz_metrics_whamm:bind_time_us,wiz_metrics_whamm:report_time_us,run_cmd')

    def __str__(self):
        res = ""
        res += f"{self.config_run_mode},{self.config_monitor},{self.config_experiment},{self.config_special},"
        res += f"{self.benchmark_suite},{self.benchmark_name},"
        res += f"{self.run_errored},"
        try:
            res += f"{'NONE' if not self.run_outfile else self.run_outfile},"
        except:
            pass
        res += f"{self.run_timed_out}"
        try:
            res += f",{RUN_TIMEOUT  if not self.run_time_mean   else fmean(self.run_time_mean)},"
        except:
            pass
        try:
            res += f"{RUN_TIMEOUT   if not self.run_time_user   else fmean(self.run_time_user)},"
        except:
            pass
        try:
            res += f"{RUN_TIMEOUT   if not self.run_time_system else fmean(self.run_time_system)}"
        except:
            pass

        if self.has_wizeng_metrics:
            try:
                res += f",{RUN_TIMEOUT if not self.wiz_metrics_pregen_time_us       else fmean(self.wiz_metrics_pregen_time_us)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_pregen_bytes          else fmean(self.wiz_metrics_pregen_bytes)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_load_time_us          else fmean(self.wiz_metrics_load_time_us)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_load_bytes            else fmean(self.wiz_metrics_load_bytes)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_load_time_per_byte    else fmean(self.wiz_metrics_load_time_per_byte)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_validate_time_us      else fmean(self.wiz_metrics_validate_time_us)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_validate_bytes        else fmean(self.wiz_metrics_validate_bytes)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_validate_time_per_byte else fmean(self.wiz_metrics_validate_time_per_byte)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_spc_in_bytes          else fmean(self.wiz_metrics_spc_in_bytes)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_spc_code_bytes        else fmean(self.wiz_metrics_spc_code_bytes)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_spc_data_bytes        else fmean(self.wiz_metrics_spc_data_bytes)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_spc_time_us           else fmean(self.wiz_metrics_spc_time_us)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_spc_functions         else fmean(self.wiz_metrics_spc_functions)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_spc_time_per_byte     else fmean(self.wiz_metrics_spc_time_per_byte)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_start_time_us         else fmean(self.wiz_metrics_start_time_us)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_main_time_us          else fmean(self.wiz_metrics_main_time_us)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_main_time_cycles      else fmean(self.wiz_metrics_main_time_cycles)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_probes_fired          else fmean(self.wiz_metrics_probes_fired)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_whamm_bind_time_us    else fmean(self.wiz_metrics_whamm_bind_time_us)},"
            except:
                pass
            try:
                res += f"{RUN_TIMEOUT if not self.wiz_metrics_whamm_report_time_us  else fmean(self.wiz_metrics_whamm_report_time_us)}"
            except:
                pass
        else:
            res += ",NONE" * 20
        try:
            res += f",{self.run_command}"
        except:
            pass
        return res

class ConfigSpecial(Enum):
    CalcBundle = "calc-bundle"
    CalcReport = "calc-report"
    NA = ""

    def __str__(self):
        return self.value

class Compilation:
    def __init__(self, monitor_module, calc_bundle_module, calc_report_module):
        self.monitor_module = monitor_module
        self.calc_bundle_module = calc_bundle_module
        self.calc_report_module = calc_report_module


Path(OUTDIR).mkdir(parents=True, exist_ok=True)
Path(ERROUT).mkdir(parents=True, exist_ok=True)
for monitor in MONITORS:
    Path(os.path.join(COMPOUT, f"whamm_engine/{monitor}")).mkdir(parents=True, exist_ok=True)
    for suite in SUITES:
        Path(os.path.join(COMPOUT, f"whamm_rewrite/{suite}/{monitor}")).mkdir(parents=True, exist_ok=True)
        Path(os.path.join(COMPOUT, f"wizard_native/{suite}/{monitor}")).mkdir(parents=True, exist_ok=True)
        Path(os.path.join(COMPOUT, f"orca_rewrite/{suite}/{monitor}")).mkdir(parents=True, exist_ok=True)
        Path(os.path.join(COMPOUT, f"wasabi/{suite}/{monitor}")).mkdir(parents=True, exist_ok=True)

with open(OUTFILE, "w") as f:
    print(Result.hdr(), file=f)

# Returns: (whether the process failed, whether the process timed out)
def run_cmd(cmd, extra_arg = "", with_timeout = False):
    split = cmd.split()
    if extra_arg != "":
        split.append(extra_arg)
    try:
        res = None
        if with_timeout:
            res = subprocess.run(split, capture_output=True, timeout=RUN_TIMEOUT)
        else:
            res = subprocess.run(split, capture_output=True)
        if res.returncode != 0:
            print(f"[ERROR] failed to run command '{cmd} {extra_arg}'\n\n{res.stderr}")
            return True, False
        return False, False
    except subprocess.TimeoutExpired:
        # Process took longer than the specified timeout
        print(f"Timeout expired for: '{cmd} {extra_arg}'\n")
        return False, True

def setup_whamm_engine(monitor, lib):
    mm_script=os.path.join(WHAMM_MM_PATH, f"{monitor}.mm")
    compout_base=os.path.join(COMPOUT, f"whamm_engine/{monitor}/{monitor}-engine.wasm")
    compout_transfer=os.path.join(COMPOUT, f"whamm_engine/{monitor}/{monitor}-engine-calc_transfer.wasm")

    # Define the base command
    base_cmd = f"{WHAMM_BIN} instr --core-lib {CORE_LIB} --script {mm_script} --wizard "
    lib_tmp = check_if_applicable("tmp", lib)
    if lib_tmp != "":
        base_cmd += f"--user-libs {lib_tmp} "

    # Base compilation
    run_cmd(base_cmd + f"-o {compout_base}")

    # Transfer overhead
    run_cmd(base_cmd + f"--no-body --no-pred -o {compout_transfer}")
    if lib_tmp == "":
        return Compilation(f"{compout_base}+{CORE_LIB}", f"{compout_transfer}+{CORE_LIB}", "")
    else:
        if lib != lib_tmp:
            # this was a temporary library, don't use during run
            return Compilation(f"{compout_base}+{CORE_LIB}", f"{compout_transfer}+{CORE_LIB}", "")
        else:
            # we want to use this library during the run
            libpath=re.sub(r'^.*=', '', lib_tmp)
            return Compilation(f"{compout_base}+{CORE_LIB}+{libpath}", f"{compout_transfer}+{CORE_LIB}+{libpath}", "")

def setup_whamm_rewrite(monitor, lib, suite, app):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, suite), app)
    app_name = Path(app_path).stem
    mm_script=os.path.join(WHAMM_MM_PATH, f"{monitor}.mm")
    compout_base=os.path.join(COMPOUT, f"whamm_rewrite/{suite}/{monitor}/{monitor}-{app_name}-rewrite.wasm")
    compout_transfer=os.path.join(COMPOUT, f"whamm_rewrite/{suite}/{monitor}/{monitor}-rewrite-calc_transfer.wasm")
    compout_report=os.path.join(COMPOUT, f"whamm_rewrite/{suite}/{monitor}/{monitor}-rewrite-calc_report.wasm")

    base_cmd = f"{WHAMM_BIN} instr --core-lib {CORE_LIB} --script {mm_script} --app {app_path} "
    if lib != "":
        base_cmd += f"--user-libs {lib} "

    # Base compilation
    run_cmd(base_cmd + f"-o {compout_base}")

    # Transfer overhead
    run_cmd(base_cmd + f"--no-body --no-pred -o {compout_transfer}")

    # Report overhead
    run_cmd(base_cmd + f"--no-report -o {compout_report}")
    if lib == "":
        return Compilation(f"{CORE_LIB} {compout_base}", f"{CORE_LIB} {compout_transfer}", f"{CORE_LIB} {compout_report}")
    else:
        libpath=re.sub(r'^.*=', '', lib)
        return Compilation(f"{CORE_LIB} {libpath} {compout_base}", f"{CORE_LIB} {libpath} {compout_transfer}", f"{CORE_LIB} {libpath} {compout_report}")

def setup_whamm_hw(monitor, lib):
    compout_base=os.path.join(WHAMM_HW_PATH, f"{monitor}-hw.wasm")
    compout_transfer=os.path.join(WHAMM_HW_PATH, f"{monitor}-hw-calc_transfer.wasm")
    compout_report=os.path.join(WHAMM_HW_PATH, f"{monitor}-hw-calc_report.wasm")

    if lib == "":
        return Compilation(f"{compout_base}+{CORE_LIB}", f"{compout_transfer}+{CORE_LIB}", f"{compout_report}+{CORE_LIB}")
    else:
        libpath=re.sub(r'^.*=', '', lib)
        return Compilation(f"{compout_base}+{CORE_LIB}+{libpath}", f"{compout_transfer}+{CORE_LIB}+{libpath}", f"{compout_report}+{CORE_LIB}+{libpath}")

def setup_orca_rewrite(monitor, lib, suite, app):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, suite), app)
    app_name = Path(app_path).stem
    instr_name = f"{app_name}-{monitor}.wasm"
    target_loc=os.path.join(COMPOUT, f"orca_rewrite/{suite}/{monitor}/{monitor}-{app_name}-rewrite.wasm")
    
    run_cmd(f"{WIRM_REWRITER} {monitor} {app_path}")
    run_cmd(f"mv {instr_name} {target_loc}")

    if lib == "":
        return Compilation(f"{CORE_LIB} {target_loc}", "", "")
    else:
        libpath=re.sub(r'^.*=', '', lib)
        return Compilation(f"{CORE_LIB} {libpath} {target_loc}", "", "")

def setup_wasabi(monitor, suite, app):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, suite), app)
    app_name = Path(app_path).stem
    mon_path=os.path.join(WASABI_MON_PATH, f"{monitor}.js")
    target_dir = os.path.join(COMPOUT, f"wasabi/{suite}/{monitor}/")
    target_loc = os.path.join(target_dir, f"{app_name}.wasabi.js")
    
    errored, timed_out = run_cmd(f"{WASABI} {app_path} -o {target_dir}")
    if errored or timed_out:
        # If command failed, don't run the benchmark
        return None
    else:
        return Compilation(f" {target_loc} {mon_path} {WASABI_RUNNER} -- {target_dir}{app_name}.wasm", "", "")

def extract_num(str):
    # Only returns the first one
    pattern = r'\d+(?:\.\d+)?'
    numbers = re.findall(pattern, str)
    return float(numbers[0])

def has_errors(out):
    cmd = f"grep -i -e {' -e '.join(ERR_STRS)} {out}"
    res = subprocess.run(cmd.split(), capture_output=True)

    # If got zero exit code, there was an error (grep found an error string)
    return res.returncode == 0

def save_outfile(out):
    newpath = os.path.join(ERROUT, f"{uuid.uuid4().hex}.out")
    shutil.move(out, newpath)

    return newpath

def process_metrics(result, errored, timed_out, out, timing_csv, has_wizeng_metrics):
    too_long = False
    if errored or timed_out:
        result.timed_out_res(errored, timed_out, save_outfile(out))
        return True

    with open(timing_csv, mode = 'r') as file:
        reader = csv.DictReader(file)
        data = next(reader)
        too_long = float(data["mean"]) >= TOO_LONG
        
        # Check if 'out' has erroring in it
        saved_outfile = None
        if has_errors(out):
            errored = True
            saved_outfile = save_outfile(out)

        result.run_res(errored, timed_out, data['command'], saved_outfile, float(data["mean"]), float(data["stddev"]), float(data["median"]), float(data["user"]), float(data["system"]), float(data["min"]), float(data["max"]))
    
    if errored or timed_out:
        # No helpful output for this case, don't process stdout
        return too_long

    if has_wizeng_metrics:
        # Read file without exploding Python memory
        cmd = f"tail -n 20 {out}"
        res = subprocess.run(cmd.split(), capture_output=True)
        stdout = None
        try:
            stdout = res.stdout.decode('utf-8')
        except:
            # There's some bug where the metrics prints out `\n\xbcs\n` at the end of a file,
            # which is invalid utf-8. Just skip over these lines!
            result.set_outfile(True, save_outfile(out))
            try:
                stdout = res.stdout[:-3].decode('utf-8')  # Exclude the last line
            except:
                # it's impossible, we're wriggling with bugs here.
                return too_long
        result.wiz_metrics(stdout)

    return too_long

def runN(cmd, result, has_wizeng_metrics):
    out=os.path.join(COMPOUT, f"{COMPOUT}/tmp.out")
    timing_csv=os.path.join(COMPOUT, f"{COMPOUT}/tmp.csv")

    too_long = False
    for i in range(RUNS):
        if too_long and i >= RUNS_FOR_LONG - 1:
            break
        errored, timed_out = run_cmd(f"{HYPERFINE_BIN} --runs 1 --export-csv {timing_csv} --output {out}", cmd, True)
        too_long |= process_metrics(result, errored, timed_out, out, timing_csv, has_wizeng_metrics)
    with open(OUTFILE, "a") as f:
        print(result, file=f)
    result.reset()

def run_engine(ty, monitor, suite, app, unit, cfgs):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, suite), app)

    for cfg in cfgs:
        result = Result(
            cfg.__str__(),
            monitor,
            ty,
            ConfigSpecial.NA,
            suite,
            app
        )
        wizeng = cfg.wizeng_bin()
        base_cmd = f"{wizeng} --metrics --ext:multi-memory --env=TO_CONSOLE=true "
        if cfg.should_jit():
            base_cmd += "--mode=jit"
        
        runN(f"{base_cmd} --monitors={unit.monitor_module} {app_path}", result, True)

        # result.config_special = ConfigSpecial.CalcBundle
        # runN(f"{base_cmd} --monitors={unit.calc_bundle_module} {app_path}", result, True)

def run_rewritten(name, monitor, suite, app, unit, cfgs):
    for cfg in cfgs:
        result = Result(
            cfg.__str__(),
            monitor,
            name,
            ConfigSpecial.NA,
            suite,
            app
        )
        wizeng = cfg.wizeng_bin()
        base_cmd = f"{wizeng} --metrics --ext:multi-memory --env=TO_CONSOLE=true "
        if cfg.should_jit():
            base_cmd += "--mode=jit"
        
        runN(f"{base_cmd} {unit.monitor_module}", result, True)

        if unit.calc_bundle_module != "":
            result.config_special = ConfigSpecial.CalcBundle
            runN(f"{base_cmd} {unit.calc_bundle_module}", result, True)

        if unit.calc_report_module != "":
            result.config_special = ConfigSpecial.CalcReport
            runN(f"{base_cmd} {unit.calc_report_module}", result, True)

def run_wizard_native(name, monitor, suite, app, cfgs):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, suite), app)

    for cfg in cfgs:
        result = Result(
            cfg.__str__(),
            monitor,
            name,
            ConfigSpecial.NA,
            suite,
            app
        )
        wizeng = cfg.wizeng_bin()
        base_cmd = f"{wizeng} --metrics --ext:multi-memory --monitors={monitor} {app_path} "
        if cfg.should_jit():
            base_cmd += "--mode=jit"
        
        runN(base_cmd, result, True)

def run_wasabi(ty, monitor, suite, app, unit, cfgs):
    for cfg in cfgs:
        result = Result(
            cfg.__str__(),
            monitor,
            ty,
            ConfigSpecial.NA,
            suite,
            app
        )
        base_cmd = f"{D8} "
        if cfg.value == "v8":
            base_cmd += "--liftoff-only "
        
        # We just reuse the first slot of the unit here (naming is off, but who cares...)
        runN(f"{base_cmd} {unit.monitor_module}", result, False)

def run_pin(name, monitor, suite, app, cfgs):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, f"{suite}-mach"), app)
    # only one cfg? ignore cfgs
    result = Result(
        "pin",
        monitor,
        name,
        ConfigSpecial.NA,
        suite,
        app
    )
    result0 = Result(
        "pin",
        monitor,
        f"{name}-ret0",
        ConfigSpecial.NA,
        suite,
        app
    )
    runN(f"{PIN_BIN} -t {PINTOOL_DIR}{monitor} -- {app_path}", result, False)
    runN(f"{PIN_BIN} -t {PINTOOL_DIR}{monitor} -- {app_path}_ret0", result0, False)

def check_if_applicable(exp, lib):
    s = f"({exp})"
    match = re.match(r'^\([a-z_]*\)', lib);
    if match == None:
        # If there wasn't a scope-limiting pattern
        return lib
    elif match[0] == s:
        # If there was a scope-limiting pattern and it applies to this case
        # print(match[0])
        return lib[len(s):]
    elif match[0] == "(tmp)" and s != "(tmp)":
        # Special case where we only want to prune tmp if we're ready
        # print(match[0])
        return lib
    else:
        # If there was a scope-limiting pattern and it DOESN'T apply to this case
        # print(match[0])
        return ""

def handle_whamm_engine(monitor, lib, cfgs):
    lib = check_if_applicable("whamm_engine", lib)
    unit = setup_whamm_engine(monitor, lib)
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, suite)):
            if app.endswith(".wasm") and app not in SKIP:
                print(f"whamm_engine::{monitor} --> {app}", flush=True)
                run_engine("whamm_engine", monitor, suite, app, unit, cfgs)
            else:
                continue

def handle_whamm_rewrite(monitor, lib, cfgs):
    lib = check_if_applicable("whamm_rewrite", lib)
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, suite)):
            if app.endswith(".wasm") and app not in SKIP:
                unit = setup_whamm_rewrite(monitor, lib, suite, app)
                print(f"whamm_rewrite::{monitor} --> {app}", flush=True)
                run_rewritten("whamm_rewrite", monitor, suite, app, unit, cfgs)
            else:
                continue

def handle_whamm_hw(monitor, lib, cfgs):
    lib = check_if_applicable("whamm_hw", lib)
    unit = setup_whamm_hw(monitor, lib)
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, suite)):
            if app.endswith(".wasm") and app not in SKIP:
                print(f"whamm_hw::{monitor} --> {app}", flush=True)
                run_engine("whamm_hw", monitor, suite, app, unit, cfgs)
            else: 
                continue

def handle_orca_rewrite(monitor, lib, cfgs):
    lib = check_if_applicable("orca_rewrite", lib)
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, suite)):
            if app.endswith(".wasm") and app not in SKIP:
                unit = setup_orca_rewrite(monitor, lib, suite, app)
                print(f"orca_rewrite::{monitor} --> {app}", flush=True)
                run_rewritten("orca_rewrite", monitor, suite, app, unit, cfgs)
            else: 
                continue

def handle_wizard_native(monitor, _lib, cfgs):
    # NOTE: library not needed for Wizard.
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, suite)):
            if app.endswith(".wasm") and app not in SKIP:
                # unit = setup_orca_rewrite(monitor, lib, suite, app)
                print(f"wizard_native::{monitor} --> {app}", flush=True)
                run_wizard_native("wizard_native", monitor, suite, app, cfgs)
            else: 
                continue

def handle_wasabi(monitor, _lib, cfgs):
    # NOTE: library not needed for Wasabi.
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, suite)):
            if app.endswith(".wasm") and app not in SKIP:
                print(f"wasabi::{monitor} --> {app}", flush=True)
                unit = setup_wasabi(monitor, suite, app)
                if unit == None:
                    print(f"\tFailed to setup!", flush=True)
                    continue;
                run_wasabi("wasabi", monitor, suite, app, unit, cfgs)
            else: 
                continue

def handle_pin(monitor, _lib, cfgs):
    # only one pin mode
    if monitor not in PINTOOLS:
        return
    monitor = PINTOOLS[monitor]
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, f"{suite}-mach")):
            if app.endswith("ret0"):
                continue
            print(f"pin::{monitor} --> {app}", flush=True)
            run_pin("pin", monitor, suite, app, cfgs)

def run_exp(ty, cfgs):
    for monitor,lib in MONITORS.items():
        # NOTE: *remove* monitors can only be handled by the engine
        if "remove" in monitor and ty != "whamm_engine":
            continue;

        if ty == 'whamm_engine':
            handle_whamm_engine(monitor, lib, cfgs)
        elif ty == 'whamm_rewrite':
            handle_whamm_rewrite(monitor, lib, cfgs)
        elif ty == 'whamm_hw':
            handle_whamm_hw(monitor, lib, cfgs)
        elif ty == 'orca_rewrite':
            handle_orca_rewrite(monitor, lib, cfgs)
        elif ty == 'wizard_native':
            handle_wizard_native(monitor, lib, cfgs)
        elif ty == 'wasabi':
            handle_wasabi(monitor, lib, cfgs)
        elif ty == 'pin':
            handle_pin(monitor, lib, cfgs)
        else:
            raise RuntimeError(f"incorrect type: {ty}")

def run_base(name, suite, app, should_jit):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, suite), app)

    result = Result(
        name,
        "None",
        "base-run",
        ConfigSpecial.NA,
        suite,
        app
    )
    wizeng = os.path.join(WIZ_PATH, "wizeng.x86-64-linux_default")
    base_cmd = f"{wizeng} --metrics --ext:multi-memory "
    if should_jit:
        base_cmd += "--mode=jit"
    
    runN(f"{base_cmd} {app_path}", result, True)

def run_base_wasabi(name, options, suite, app):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, suite), app)

    result = Result(
        name,
        "None",
        "base-run",
        ConfigSpecial.NA,
        suite,
        app
    )
    base_cmd = f"{D8} {options} {WASABI_RUNNER} -- "
    
    runN(f"{base_cmd} {app_path}", result, False)

def run_base_pin(name, suite, app):
    app_path = os.path.join(os.path.join(BENCHMARK_DIR, f"{suite}-mach"), app)

    result_base = Result(name, "None", "base-run", ConfigSpecial.NA, suite, app)
    result_base0 = Result(name, "None", "base-run0", ConfigSpecial.NA, suite, app)
    result_base_pin = Result(name, "None", "base-run-pin", ConfigSpecial.NA, suite, app)
    result_base_pin0 = Result(name, "None", "base-run0-pin", ConfigSpecial.NA, suite, app)

    runN(app_path, result_base, False)
    runN(f"{app_path}_ret0", result_base0, False)
    runN(f"{PIN_BIN} -- {app_path}", result_base_pin, False)
    runN(f"{PIN_BIN} -- {app_path}_ret0", result_base_pin0, False)

def run_pin_uninstr():
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, f"{suite}-mach")):
            if app.endswith("ret0"):
                continue
            print(f"base_pin --> {app}", flush=True)
            run_base_pin("pin", suite, app)

def run_uninstr():
    for suite in SUITES:
        for app in os.listdir(os.path.join(BENCHMARK_DIR, suite)):
            if app.endswith(".wasm"):
                print(f"base_int --> {app}", flush=True)
                run_base("base_int", suite, app, False)
                print(f"base_jit --> {app}", flush=True)
                run_base("base_jit", suite, app, True)

                print(f"base_v8 --> {app}", flush=True)
                run_base_wasabi("base_v8", "--liftoff-only ", suite, app)
                print(f"base_v8-prod --> {app}", flush=True)
                run_base_wasabi("base_v8-prod", "", suite, app)
            else: 
                continue
    startup = "nop-wasi.wasm"
    print(f"base_v8-startup --> {startup}", flush=True)
    run_base_wasabi("base_v8-startup", "--liftoff-only ", "startup", startup)
    print(f"base_v8-prod-startup --> {startup}", flush=True)
    run_base_wasabi("base_v8-prod-startup", "", "startup", startup)

def main():
    if RUN_BASELINES:
        run_uninstr()
        run_pin_uninstr()
    for ty,cfgs in EXPS.items():
        run_exp(ty,cfgs)
    print(f"Completed run, see output at: {OUTFILE}")

if __name__=="__main__":
    main()
