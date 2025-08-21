from utils import *

import os
import pandas  as pd
from   pathlib import Path
import sys

mypath = os.path.abspath(os.path.dirname(__file__))
OUT = "../../out"

# General setup
if len(sys.argv) != 3:
    print(f"Usage: whamm-opts_int.py <timestamp> <used_timeout>\n\t<timestamp> used to identify results to plot in output directory at {OUT}\n\t<used_timeout> is the timeout used during the experiment run (in seconds)")
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
        baseline_int_df = df[(df['config:run_mode'] == 'base_int') & (df['benchmark:suite'] == SUITE)]
        assert not baseline_int_df.empty, "No baselines available, cannot plot results!"
        mon_df = df[
            (df['config:monitor'] == mon) & (df['benchmark:suite'] == SUITE) & (df['config:special'].isna())]

        for benchmark_name in mon_df['benchmark:name'].unique():
            baseline_data = baseline_int_df[baseline_int_df['benchmark:name'] == benchmark_name]
            base_int = baseline_data[RUNTIME_MEASUREMENT].values[0]

            new_row = {
                'suite': SUITE,
                'benchmark': benchmark_name,
                'time-int': base_int
            }
            engine_data = mon_df[(mon_df['config:experiment'] == WHAMM_ENGINE) & (
                        mon_df['benchmark:name'] == benchmark_name)]

            try:
                int_rt_int = engine_data[engine_data['config:run_mode'] == 'int-rt-int'][RUNTIME_MEASUREMENT].values[0]
                new_row['$\\it{wei}$, int-rt-int'] = int_rt_int / base_int
            except:
                print("missing data point for 'int_rt_int'")

            try:
                int_rt_jit = engine_data[engine_data['config:run_mode'] == 'int-rt-jit'][RUNTIME_MEASUREMENT].values[0]
                new_row['$\\it{wei}$, int-rt-jit'] = int_rt_jit / base_int
            except:
                print("missing data point for 'int_rt_jit'")

            try:
                int_tramp_int = engine_data[engine_data['config:run_mode'] == 'int-tramp-int'][RUNTIME_MEASUREMENT].values[
                    0]
                new_row['$\\it{wei}$, int-tramp-int'] = int_tramp_int / base_int
            except:
                print("missing data point for 'int_tramp_int'")

            try:
                int_tramp_jit = engine_data[engine_data['config:run_mode'] == 'int-tramp-jit'][RUNTIME_MEASUREMENT].values[
                    0]
                new_row['$\\it{wei}$, int-tramp-jit'] = int_tramp_jit / base_int
            except:
                print("missing data point for 'int_tramp_jit'")

            rewriting_df = df[(df['config:monitor'] == mon) & (df['benchmark:suite'] == SUITE)]
            rewriting_data = rewriting_df[(rewriting_df['config:experiment'] == WHAMM_REWRITE) & (
                        rewriting_df['benchmark:name'] == benchmark_name) & (
                                                      rewriting_df['config:special'] == 'calc_report')]
            try:
                rewrite_int = \
                rewriting_data[rewriting_data['config:run_mode'] == 'int-default'][RUNTIME_MEASUREMENT].values[0]
                new_row['Whamm rewriting, int'] = rewrite_int / base_int
            except:
                print("skipping data point for 'rewrite_int'")

            # (Calculate relative overhead here)
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

branches_df_thirds = make_thirds_int(branches_df)
hotness_df_thirds = make_thirds_int(hotness_df)
icount_df_thirds = make_thirds_int(icount_df)
imix_df_thirds = make_thirds_int(imix_df)
cache_df_thirds = make_thirds_int(cache_df)
mem_access_df_thirds = make_thirds_int(mem_access_df)
loop_tracer_df_thirds = make_thirds_int(loop_tracer_df)
basic_blocks_df_thirds = make_thirds_int(basic_blocks_df)
instr_coverage_df_thirds = make_thirds_int(instr_coverage_df)
call_graph_df_thirds = make_thirds_int(call_graph_df)

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

        to_plot = ['$\\it{wei}$, int-rt-int', '$\\it{wei}$, int-rt-jit', '$\\it{wei}$, int-tramp-int',
                   '$\\it{wei}$, int-tramp-jit']
        colors = ['firebrick', 'sandybrown', 'mediumseagreen', 'royalblue']

        # Setting y-axis to logarithmic scale (base 10)
        ax.set_yscale('log')
        ax.set_ylim(1, ylim)

        groups = df["group"].unique()

        offsets = np.linspace(-0.3, 0.3, len(to_plot))

        for j, group_id in enumerate(groups):
            for k, item in enumerate(to_plot):
                values = df[df["group"] == group_id][item]
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
            ax.set_xticklabels(["polybench-short", "polybench-medium", "polybench-long"], fontsize=12, rotation=0)
            plt.xlabel('Benchmark Sub-Suite', fontsize=17, fontweight='bold')
        else:
            ax.set_xticklabels([])

        # Build the legend
        if i == 0:
            legend_handles = [Patch(facecolor=c, alpha=0.7, label=lab)
                              for c, lab in zip(colors, to_plot)]
            ax.legend(handles=legend_handles, fontsize=9, loc='upper right', ncol=2)

        ax.text(-0.4, ylim * 0.90, mon_name, fontsize=18, fontweight='bold', va='top')

        # Adding labels and title
        ax.grid(True, axis='y', zorder=0)

    fig.text(0.5, 1.01, '$\\it{wei}$ Interpreter Optimizations', ha='center', va='top', fontsize=20, fontweight='bold')
    fig.text(-.003, 0.56, f'Relative Overhead', ha='left', va='center', fontsize=17, fontweight='bold', rotation=90)
    # Automatically adjust the layout for better spacing
    plt.tight_layout()

    plt.savefig(f"{OUTDIR_PLOTS}/RERUN-int-opts-all-monitors.pdf", bbox_inches='tight')


branches_df_thirds_cfg = (branches_df_thirds, 1e1, 'branches', False)
hotness_df_thirds_cfg = (hotness_df_thirds, 1e3, 'hotness', False)
icount_df_thirds_cfg = (icount_df_thirds, 1e3, 'icount', False)
imix_df_thirds_cfg = (imix_df_thirds, 1e3, 'imix', False)
cache_df_thirds_cfg = (cache_df_thirds, 1e2, 'cache-sim', False)
mem_access_df_thirds_cfg = (mem_access_df_thirds, 1e4, 'mem-access', False)
loop_tracer_df_thirds_cfg = (loop_tracer_df_thirds, 1e2, 'loop-tracer', False)
basic_blocks_df_thirds_cfg = (basic_blocks_df_thirds, 1e1, 'basic-blocks', False)
instr_coverage_df_thirds_cfg = (instr_coverage_df_thirds, 1e3, 'instr-coverage', False)
call_graph_df_thirds_cfg = (call_graph_df_thirds, 1e1, 'call-graph', True)
plot_df_grouped([branches_df_thirds_cfg, hotness_df_thirds_cfg, icount_df_thirds_cfg, imix_df_thirds_cfg,
                  cache_df_thirds_cfg,
                    mem_access_df_thirds_cfg, loop_tracer_df_thirds_cfg, basic_blocks_df_thirds_cfg,
                    instr_coverage_df_thirds_cfg,
                      call_graph_df_thirds_cfg])
