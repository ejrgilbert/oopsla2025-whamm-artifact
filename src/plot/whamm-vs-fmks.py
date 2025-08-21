from utils import *

import os
import pandas  as pd
from   pathlib import Path
import sys

mypath = os.path.abspath(os.path.dirname(__file__))
OUT = "../../out"

# General setup
if len(sys.argv) != 3:
    print(f"Usage: whamm-vs-fmks.py <timestamp> <used_timeout>\n\t<timestamp> used to identify results to plot in output directory at {OUT}\n\t<used_timeout> is the timeout used during the experiment run (in seconds)")
    sys.exit(1)
timestamp = sys.argv[1]
timeout_s = sys.argv[2]

OUTDIR = os.path.join(mypath, f"{OUT}/{timestamp}/results")
OUTDIR_PLOTS = os.path.join(mypath, f"{OUT}/{timestamp}/results/plots")

Path(OUTDIR_PLOTS).mkdir(parents=True, exist_ok=True)

# Read in and clean up the data
df = pd.read_csv(f"{OUTDIR}/{timestamp}.csv", low_memory=False)
df = clean(df, timeout_s)

WHAMM_ENGINE = 'whamm_engine'
WHAMM_REWRITE = 'whamm_rewrite'
WHAMM_HW = 'whamm_hw'
ENGINE_NATIVE = 'wizard_native'
WASABI = 'wasabi'
ORCA = 'orca_rewrite'

RUNTIME_MEASUREMENT = 'run_time:mean'

# ===============================
# ==== COLLECT RELEVANT DATA ====
# ===============================

def get_monitor_df(mon):
    new_df_rows = []
    for SUITE in ["polybench"]:
        baseline_jit_df = df[(df['config:run_mode'] == 'base_jit') & (df['benchmark:suite'] == SUITE)]
        assert not baseline_jit_df.empty, "No baselines available, cannot plot results!"
        mon_df = df[
            (df['config:monitor'] == mon) & (df['benchmark:suite'] == SUITE) & (df['config:special'].isna())]

        for benchmark_name in mon_df['benchmark:name'].unique():
            baseline_data = baseline_jit_df[baseline_jit_df['benchmark:name'] == benchmark_name]
            base_jit = baseline_data[RUNTIME_MEASUREMENT].values[0]

            new_row = {
                'suite': SUITE,
                'benchmark': benchmark_name,
                'time-jit': base_jit
            }

            engine_data = mon_df[(mon_df['config:experiment'] == WHAMM_ENGINE) &
                                 (mon_df['benchmark:name'] == benchmark_name)]
            try:
                engine_inline = engine_data[engine_data['config:run_mode'] == 'inline'][RUNTIME_MEASUREMENT].values[0]
                new_row['$\\it{wei}$, inlined'] = engine_inline / base_jit
            except:
                print(f"[{mon}] missing data point for 'engine_inline'")

            rewriting_data = mon_df[(mon_df['config:experiment'] == WHAMM_REWRITE) & (mon_df['benchmark:name'] == benchmark_name)]
            try:
                rewrite_jit = rewriting_data[rewriting_data['config:run_mode'] == 'jit-default'][RUNTIME_MEASUREMENT].values[0]
                new_row['Whamm rewriting, jit'] = rewrite_jit / base_jit
            except:
                print(f"[{mon}] missing data point for 'rewrite_jit'")

            hw_data = mon_df[(mon_df['config:experiment'] == WHAMM_HW) &
                             (mon_df['benchmark:name'] == benchmark_name)]
            try:
                hw_inline = hw_data[hw_data['config:run_mode'] == 'inline'][RUNTIME_MEASUREMENT].values[0]
                new_row['$\\it{wei}$-handwritten, inlined'] = hw_inline / base_jit
            except:
                print(f"[{mon}] missing data point for 'hw_inline'")

            native_data = mon_df[(mon_df['config:experiment'] == ENGINE_NATIVE) & (mon_df['benchmark:name'] == benchmark_name)]
            try:
                native_time = native_data[native_data['config:run_mode'] == 'jit-default'][RUNTIME_MEASUREMENT].values[0]
                new_row['engine-native, jit'] = native_time / base_jit
            except:
                print(f"[{mon}] missing data point for 'native_time'")

            wasabi_data = mon_df[(mon_df['config:experiment'] == WASABI) & (mon_df['benchmark:name'] == benchmark_name)]
            try:
                wasabi_time = wasabi_data[wasabi_data['config:run_mode'] == 'v8'][RUNTIME_MEASUREMENT].values[0]
                base_v8 = df[df['benchmark'] == benchmark_name]['BASE (v8)'].values[0]
                new_row['wasabi, v8'] = wasabi_time / base_v8
            except:
                print(f"[{mon}] missing data point for 'wasabi'")

            orca_data = mon_df[(mon_df['config:experiment'] == ORCA) & (mon_df['benchmark:name'] == benchmark_name)]
            try:
                orca_jit = orca_data[orca_data['config:run_mode'] == 'jit-default'][RUNTIME_MEASUREMENT].values[0]
                new_row['wirm rewriting, jit'] = orca_jit / base_jit
            except:
                print(f"[{mon}] missing data point for 'orca_jit'")

            new_df_rows.append(new_row)

    return pd.DataFrame(new_df_rows)

branches_df = get_monitor_df('branches')
hotness_df = get_monitor_df('hotness')
icount_df = get_monitor_df('icount')
imix_df = get_monitor_df('imix')
cache_df = get_monitor_df('cache-sim')
mem_access_df = get_monitor_df('mem-access')
loop_tracer_df = get_monitor_df('loop-tracer')
basic_blocks_df = get_monitor_df('basic-blocks')
instr_coverage_df = get_monitor_df('instr-coverage')
call_graph_df = get_monitor_df('call-graph')

# ===============================
# ==== GROUP INTO SUB-SUITES ====
# ===============================

cols = {
    '$\\it{wei}$-handwritten, inlined': "$\\it{wei}$-handwritten, inlined",
    '$\\it{wei}$, inlined': "$\\it{wei}$, inlined",
    'Whamm rewriting, jit': "Whamm rewriting, jit",
    'wirm rewriting, jit': "wirm rewriting, jit",
    'engine-native, jit': "engine-native, jit",
    'wasabi, v8': "wasabi, v8"
}

branches_df_thirds = make_thirds_jit(branches_df, True, cols)
hotness_df_thirds = make_thirds_jit(hotness_df, True, cols)
icount_df_thirds = make_thirds_jit(icount_df, True, cols)
imix_df_thirds = make_thirds_jit(imix_df, True, cols)
cache_df_thirds = make_thirds_jit(cache_df, True, cols)
mem_access_df_thirds = make_thirds_jit(mem_access_df, True, cols)
loop_tracer_df_thirds = make_thirds_jit(loop_tracer_df, True, cols)
basic_blocks_df_thirds = make_thirds_jit(basic_blocks_df, True, cols)
instr_coverage_df_thirds = make_thirds_jit(instr_coverage_df, True, cols)
call_graph_df_thirds = make_thirds_jit(call_graph_df, True, cols)

# =======================
# ==== PLOT THE DATA ====
# =======================

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Patch


def plot_df_grouped(configs):
    num = 5
    fig, axs = plt.subplots(num, 2, figsize=(18, 2.5 * num))
    for i, config in enumerate(configs):
        axs = axs.flatten()
        ax = axs[i]
        df, ylim, mon_name, order, include_benchmarks_label = config

        # Setting y-axis to logarithmic scale (base 10)
        ax.set_yscale('log')
        ax.set_ylim(1, ylim)

        color_key = {
            'wirm rewriting, jit': 'sandybrown',
            'engine-native, jit': 'firebrick',
            '$\\it{wei}$-handwritten, inlined': 'lightpink',
            '$\\it{wei}$, inlined': 'royalblue',
            'Whamm rewriting, jit': 'indigo',
            'wasabi, v8': 'mediumseagreen'
        }
        colors = [color_key[i] for i in order]

        groups = df["group"].unique()

        width = 0.9  # total width per group
        offsets = np.linspace(-width / 3, width / 3, len(order))

        for j, group in enumerate(groups):
            for k, item in enumerate(order):
                try:
                    values = df[df["group"] == group][item]
                except: continue
                pos = j + offsets[k]
                parts = ax.violinplot(values, positions=[pos], widths=0.25, showmeans=True)

                # Color the violin body
                for pc in parts['bodies']:
                    pc.set_facecolor(color_key[item])
                    pc.set_alpha(0.7)
                    pc.set_zorder(4)
                for key in ['cmeans', 'cmedians', 'cbars', 'cmins', 'cmaxes']:
                    if key in parts:
                        parts[key].set_color("black")

        # Set custom x-axis labels
        ax.set_xticks(range(0, 3))
        if include_benchmarks_label:
            ax.set_xticklabels(["polybench-short", "polybench-medium", "polybench-long"], fontsize=12,
                               rotation=0)  # Set the x-tick labels
        else:
            ax.set_xticklabels([])

        # Build legend
        if i == 1:
            legend_handles = [Patch(facecolor=c, alpha=0.7, label=lab)
                              for c, lab in zip(colors, order)]
            ax.legend(handles=legend_handles, loc='upper right', ncol=2)

        ax.text(-0.5, ylim * 0.9, mon_name, fontsize=18, fontweight='bold', va='top')
        ax.grid(True, axis='y', zorder=0)

    fig.text(0.5, 1.02, f'Whamm vs State-of-the-Art Wasm Instrumentation Frameworks', ha='center', va='top',
             fontsize=20, fontweight='bold')
    fig.text(-0.01, 0.56, f'Relative Overhead', ha='left', va='center', fontsize=17, fontweight='bold', rotation=90)
    fig.text(0.5, -.01, 'Benchmark Sub-Suite', ha='center', va='bottom', fontsize=17, fontweight='bold')
    # Automatically adjust the layout for better spacing
    plt.tight_layout()

    plt.savefig(f"{OUTDIR_PLOTS}/whamm-vs-fmks.pdf", bbox_inches='tight')


targets = [
    'Whamm rewriting, jit',
    'wirm rewriting, jit',
    '$\\it{wei}$, inlined',
    '$\\it{wei}$-handwritten, inlined',
    'engine-native, jit',
    'wasabi, v8'
]

branches_df_thirds_cfg = (branches_df_thirds, 1e3, 'branches', targets, False)
hotness_df_thirds_cfg = (hotness_df_thirds, 1e4, 'hotness', targets, False)
icount_df_thirds_cfg = (icount_df_thirds, 1e3, 'icount', targets, False)
imix_df_thirds_cfg = (imix_df_thirds, 1e3, 'imix', targets, False)
cache_df_thirds_cfg = (cache_df_thirds, 1e4, 'cache-sim', targets, False)
mem_access_df_thirds_cfg = (mem_access_df_thirds, 1e5, 'mem-access', targets, False)
loop_tracer_df_thirds_cfg = (loop_tracer_df_thirds, 1e3, 'loop-tracer', targets, False)
basic_blocks_df_thirds_cfg = (basic_blocks_df_thirds, 1e3, 'basic-blocks', targets, False)
instr_coverage_df_thirds_cfg = (instr_coverage_df_thirds, 1e4, 'instr-coverage', targets, True)
call_graph_df_thirds_cfg = (call_graph_df_thirds, 1e4, 'call-graph', targets, True)
plot_df_grouped([branches_df_thirds_cfg, hotness_df_thirds_cfg, icount_df_thirds_cfg, imix_df_thirds_cfg, cache_df_thirds_cfg, mem_access_df_thirds_cfg, loop_tracer_df_thirds_cfg, basic_blocks_df_thirds_cfg,
                  instr_coverage_df_thirds_cfg,
                  call_graph_df_thirds_cfg
                  ])
