from utils import *

import os
import pandas  as pd
from   pathlib import Path
import sys

mypath = os.path.abspath(os.path.dirname(__file__))
OUT = "../../out"

# General setup
if len(sys.argv) != 3:
    print(f"Usage: whamm-opts_jit.py <timestamp> <used_timeout>\n\t<timestamp> used to identify results to plot in output directory at {OUT}\n\t<used_timeout> is the timeout used during the experiment run (in seconds)")
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
RUNTIME_MEASUREMENT = 'wiz_metrics_main:time_us'

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
            engine_data = mon_df[(mon_df['config:experiment'] == WHAMM_ENGINE) & (
                        mon_df['benchmark:name'] == benchmark_name)]

            try:
                jit_rt_int = engine_data[engine_data['config:run_mode'] == 'jit-rt-int'][RUNTIME_MEASUREMENT].values[0]
                new_row['$\\it{wei}$, jit-rt-int'] = jit_rt_int / base_jit
            except:
                print("missing data point for 'jit_rt_int'")

            try:
                jit_rt_jit = engine_data[engine_data['config:run_mode'] == 'jit-rt-jit'][RUNTIME_MEASUREMENT].values[0]
                new_row['$\\it{wei}$, jit-rt-jit'] = jit_rt_jit / base_jit
            except:
                print("missing data point for 'jit_rt_jit'")

            try:
                jit_wasm_int = engine_data[engine_data['config:run_mode'] == 'jit-wasm-int'][RUNTIME_MEASUREMENT].values[
                    0]
                new_row['$\\it{wei}$, jit-wasm-int'] = jit_wasm_int / base_jit
            except:
                print("missing data point for 'jit_wasm_int'")

            try:
                jit_wasm_jit = engine_data[engine_data['config:run_mode'] == 'jit-wasm-jit'][RUNTIME_MEASUREMENT].values[
                    0]
                new_row['$\\it{wei}$, jit-wasm-jit'] = jit_wasm_jit / base_jit
            except:
                print("missing data point for 'jit_wasm_jit'")

            try:
                inline = engine_data[engine_data['config:run_mode'] == 'inline'][RUNTIME_MEASUREMENT].values[
                    0]
                new_row['$\\it{wei}$, inlined'] = inline / base_jit
            except:
                print("missing data point for 'inline'")

            rewriting_df = df[(df['config:monitor'] == mon) & (df['benchmark:suite'] == SUITE)]
            rewriting_data = rewriting_df[(rewriting_df['config:experiment'] == WHAMM_REWRITE) & (
                        rewriting_df['benchmark:name'] == benchmark_name)]
            try:
                rewrite_jit = \
                rewriting_data[rewriting_data['config:run_mode'] == 'jit-default'][RUNTIME_MEASUREMENT].values[0]
                new_row['Whamm rewriting, jit'] = rewrite_jit / base_jit
            except:
                print("skipping data point for 'rewrite_jit'")

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
    '$\\it{wei}$, jit-rt-int': '$\\it{wei}$, jit-rt-int',
    '$\\it{wei}$, jit-rt-jit': '$\\it{wei}$, jit-rt-jit',
    '$\\it{wei}$, jit-wasm-int': '$\\it{wei}$, jit-wasm-int',
    '$\\it{wei}$, jit-wasm-jit': '$\\it{wei}$, jit-wasm-jit',
    '$\\it{wei}$, inlined': '$\\it{wei}$, inlined',
    'Whamm rewriting, jit': '$Whamm$ rewriting, jit'
}

branches_df_thirds = make_thirds_jit(branches_df, cols)
hotness_df_thirds = make_thirds_jit(hotness_df, cols)
icount_df_thirds = make_thirds_jit(icount_df, cols)
imix_df_thirds = make_thirds_jit(imix_df, cols)
cache_df_thirds = make_thirds_jit(cache_df, cols)
mem_access_df_thirds = make_thirds_jit(mem_access_df, cols)
loop_tracer_df_thirds = make_thirds_jit(loop_tracer_df, cols)
basic_blocks_df_thirds = make_thirds_jit(basic_blocks_df, cols)
instr_coverage_df_thirds = make_thirds_jit(instr_coverage_df, cols)
call_graph_df_thirds = make_thirds_jit(call_graph_df, cols)

# =======================
# ==== PLOT THE DATA ====
# =======================

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Patch


def plot_df_grouped(configs):
    num = len(configs)
    fig, axs = plt.subplots(num, 1, figsize=(8, 2.2 * num))
    for i, config in enumerate(configs):
        ax = axs[i]
        df, ylim, mon_name, include_benchmarks_label = config

        to_plot = ['$\\it{wei}$, jit-rt-int', '$\\it{wei}$, jit-rt-jit', '$\\it{wei}$, jit-wasm-int',
                   '$\\it{wei}$, jit-wasm-jit', '$\\it{wei}$, inlined']
        colors = ['firebrick', 'sandybrown', 'mediumseagreen', 'royalblue', 'gold', 'indigo']

        # Setting y-axis to logarithmic scale (base 10)
        ax.set_yscale('log')
        ax.set_ylim(1, ylim)

        groups = df["group"].unique()

        offsets = np.linspace(-0.3, 0.3, len(to_plot))

        for j, group in enumerate(groups):
            for k, item in enumerate(to_plot):
                values = df[df["group"] == group][item]
                pos = j + offsets[k]
                parts = ax.violinplot(values, positions=[pos], widths=0.25, showmeans=True)

                # Color the violin body
                for pc in parts['bodies']:
                    pc.set_facecolor(colors[k])
                    pc.set_alpha(0.7)
                    pc.set_zorder(4)
                for key in ['cmeans', 'cmedians', 'cbars', 'cmins', 'cmaxes']:
                    if key in parts:
                        parts[key].set_color("black")

        # Set custom x-axis labels
        ax.set_xticks(range(0, len(groups)))
        if include_benchmarks_label:
            ax.set_xticklabels(["polybench-short", "polybench-medium", "polybench-long"], fontsize=12,
                               rotation=0)  # Set the x-tick labels
            plt.xlabel('Benchmark Sub-Suite', fontsize=17, fontweight='bold')
        else:
            ax.set_xticklabels([])

        # Build legend
        if i == 0:
            legend_handles = [Patch(facecolor=c, alpha=0.7, label=lab)
                              for c, lab in zip(colors, to_plot)]
            ax.legend(handles=legend_handles, fontsize=9, loc='upper right', ncol=2)

        ax.text(-0.4, ylim * 0.90, mon_name, fontsize=18, fontweight='bold', va='top')

        # Adding gridlines, labels and title
        ax.grid(True, axis='y', zorder=0)

    fig.text(0.5, 1.01, '$\\it{wei}$ JIT Optimizations', ha='center', va='top', fontsize=20, fontweight='bold')

    # This keeps the height the same for the side-by-side rendering in the paper
    fig.text(-.003, 0.56, f' ', ha='left', va='center', fontsize=17, fontweight='bold', rotation=90)
    # Automatically adjust the layout for better spacing
    plt.tight_layout()
    plt.savefig(f"{OUTDIR_PLOTS}/jit-opts-all-monitors.pdf", bbox_inches='tight')

branches_df_thirds_cfg = (branches_df_thirds, 1e3, 'branches', False)
hotness_df_thirds_cfg = (hotness_df_thirds, 1e4, 'hotness', False)
icount_df_thirds_cfg = (icount_df_thirds, 1e4, 'icount', False)
imix_df_thirds_cfg = (imix_df_thirds, 1e4, 'imix', False)
cache_df_thirds_cfg = (cache_df_thirds, 1e4, 'cache-sim', False)
mem_access_df_thirds_cfg = (mem_access_df_thirds, 1e7, 'mem-access', False)
loop_tracer_df_thirds_cfg = (loop_tracer_df_thirds, 1e3, 'loop-tracer', False)
basic_blocks_df_thirds_cfg = (basic_blocks_df_thirds, 1e2, 'basic-blocks', False)
instr_coverage_df_thirds_cfg = (instr_coverage_df_thirds, 1e5, 'instr-coverage', False)
call_graph_df_thirds_cfg = (call_graph_df_thirds, 1e2, 'call-graph', True)
plot_df_grouped([branches_df_thirds_cfg, hotness_df_thirds_cfg, icount_df_thirds_cfg, imix_df_thirds_cfg,
                  cache_df_thirds_cfg,
                    mem_access_df_thirds_cfg, loop_tracer_df_thirds_cfg, basic_blocks_df_thirds_cfg,
                  instr_coverage_df_thirds_cfg,
                    call_graph_df_thirds_cfg
                    ])
