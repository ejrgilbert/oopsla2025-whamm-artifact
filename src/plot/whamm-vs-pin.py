from utils import *

import os
import pandas  as pd
from   pathlib import Path
import sys

mypath = os.path.abspath(os.path.dirname(__file__))
OUT = "../../out"

# General setup
if len(sys.argv) != 3:
    print(f"Usage: whamm-vs-pin.py <timestamp> <used_timeout>\n\t<timestamp> used to identify results to plot in output directory at {OUT}\n\t<used_timeout> is the timeout used during the experiment run (in seconds)")
    sys.exit(1)
timestamp = sys.argv[1]
timeout_s = sys.argv[2]

OUTDIR = os.path.join(mypath, f"{OUT}/{timestamp}/results")
OUTDIR_PLOTS = os.path.join(mypath, f"{OUT}/{timestamp}/results/plots")

Path(OUTDIR_PLOTS).mkdir(parents=True, exist_ok=True)

# Read in and clean up the data
df = pd.read_csv(f"{OUTDIR}/{timestamp}.csv", low_memory=False)
df = clean(df, timeout_s)

SUITE = 'polybench'
WHAMM_ENGINE = 'whamm_engine'
WHAMM_REWRITE = 'whamm_rewrite'

MODE = 'inline'
MEAN = 'run_time:mean'
WIZ_BIND = 'wiz_metrics_whamm:bind_time_us'
WIZ_REPORT = 'wiz_metrics_whamm:report_time_us'

SPEC_BUNDLE = 'calc-bundle'
SPEC_REPORT = 'calc-report'


# ===============================
# ==== COLLECT RELEVANT DATA ====
# ===============================

# Baseline JIT data
baseline_polybench_jit_df = df[(df['config:run_mode'] == 'base_jit') & (df['benchmark:suite'] == SUITE)]

# Whamm engine data
def whamm_engine_df(mon):
    # Monitor data, polybench data!
    monitor_polybench_df = df[(df['config:monitor'] == mon) & (df['benchmark:suite'] == SUITE)]

    new_df_rows = []
    for benchmark_name in monitor_polybench_df['benchmark:name'].unique():
        try:
            baseline_data = baseline_polybench_jit_df[baseline_polybench_jit_df['benchmark:name'] == benchmark_name]
            base_jit = baseline_data[MEAN].values[0]
        except:
            print(f"[{benchmark_name}] skipping, no baseline data")
            continue

        # ENGINE
        # bind time: wiz_bind
        # report time: wiz_report
        # transfer time: mean_bundle - (mean_uninstr + wiz_report + wiz_bind)
        # instr time: mean - mean_bundle    # (mean_bundle includes wiz_report time)
        # CHECK TOTAL AT THE END!!

        engine_data = monitor_polybench_df[(monitor_polybench_df['config:experiment'] == WHAMM_ENGINE) & (
                    monitor_polybench_df['benchmark:name'] == benchmark_name)]
        # assert len(engine_data) == 22, f"found wrong number of results, expected 22: {len(engine_data)}"

        mean = engine_data[(engine_data['config:run_mode'] == MODE) & (engine_data['config:special'].isna())][MEAN].values[0]
        mean_bundle = engine_data[(engine_data['config:run_mode'] == MODE) & (engine_data['config:special'] == SPEC_BUNDLE)][MEAN].astype(float).values[0]

        bind_time_us = engine_data[(engine_data['config:run_mode'] == MODE) & (engine_data['config:special'].isna())][WIZ_BIND].astype(float).values[0]
        bind_time = bind_time_us / 1000000
        assert bind_time >= 0, f"bind_time is negative! {bind_time}"

        report_time_us = engine_data[(engine_data['config:run_mode'] == MODE) & (engine_data['config:special'].isna())][
            WIZ_REPORT].astype(float).values[0]
        report_time = report_time_us / 1000000
        assert report_time >= 0, f"report_time is negative! {report_time}"

        transfer_time = mean_bundle - (base_jit + bind_time + report_time)
        if transfer_time < 0:
            transfer_time = 0

        instr_time = mean - mean_bundle
        assert instr_time >= 0, f"instr_time is negative! {instr_time}"

        total = base_jit + (bind_time + report_time + transfer_time + instr_time)
        assert round(total, 3) == round(mean, 3), f"calculation not right, exp: {mean}, actual: {total}"

        new_df_rows.append({
            'suite': SUITE,
            'benchmark': benchmark_name,
            'time-jit': base_jit,
            # 'base-instr': mean,
            'bind': bind_time,  # microseconds -> seconds
            'transfer': transfer_time,
            'instr': instr_time,
            'report': report_time  # microseconds -> seconds
        })

    return pd.DataFrame(new_df_rows)

imix_engine_df = whamm_engine_df('imix')
imix_engine_df['base bind'] = 0

cache_engine_df = whamm_engine_df('cache-sim')
cache_engine_df['base bind'] = 0

icount_engine_df = whamm_engine_df('icount')
icount_engine_df['base bind'] = 0

# Whamm rewrite data
def whamm_rewrite_df(mon, has_transfer):
    # Monitor data, polybench data!
    monitor_polybench_df = df[(df['config:monitor'] == mon) & (df['benchmark:suite'] == SUITE)]

    new_df_rows = []
    for benchmark_name in monitor_polybench_df['benchmark:name'].unique():
        try:
            baseline_data = baseline_polybench_jit_df[baseline_polybench_jit_df['benchmark:name'] == benchmark_name]
            base_jit = baseline_data[MEAN].values[0]
        except:
            print(f"[{benchmark_name}] skipping, no baseline data")
            continue

        # REWRITING
        # bind time: 0
        # report time: mean - mean_report
        # transfer time: mean-bundle - (mean_uninstr + report_time)
        # instr time: mean - mean_bundle
        # CHECK TOTAL AT THE END!!

        rewrite_data = monitor_polybench_df[(monitor_polybench_df['config:experiment'] == WHAMM_REWRITE) & (
                    monitor_polybench_df['benchmark:name'] == benchmark_name)]
        assert len(rewrite_data) == 6, f"found wrong number of results, expected 6: {len(rewrite_data)}"

        mean = \
        rewrite_data[(rewrite_data['config:run_mode'] == 'jit-default') & (rewrite_data['config:special'].isna())][
            MEAN].values[0]
        mean_bundle = rewrite_data[
            (rewrite_data['config:run_mode'] == 'jit-default') & (rewrite_data['config:special'] == SPEC_BUNDLE)][
            MEAN].values[0]
        mean_report = rewrite_data[
            (rewrite_data['config:run_mode'] == 'jit-default') & (rewrite_data['config:special'] == SPEC_REPORT)][
            MEAN].values[0]

        report_time = mean - mean_report
        if report_time < 0:
            report_time = 0
        transfer_time = mean_bundle - (base_jit + report_time)
        if transfer_time < 0 or not has_transfer:
            transfer_time = 0
        instr_time = mean - mean_bundle
        if instr_time < 0:
            instr_time = 0

        if transfer_time == 0:
            instr_time = mean - (base_jit + report_time)

        total = base_jit + (report_time + transfer_time + instr_time)
        assert round(total, 3) == round(mean, 3), f"calculation not right, exp: {mean}, actual: {total}"

        new_df_rows.append({
            'suite': SUITE,
            'benchmark': benchmark_name,
            'time-jit': base_jit,
            # 'base-instr': mean,
            'transfer': transfer_time,
            'instr': instr_time,
            'report': report_time  # microseconds -> seconds
        })

    return pd.DataFrame(new_df_rows)

imix_rewrite_df = whamm_rewrite_df('imix', False)
imix_rewrite_df['base bind'] = 0
imix_rewrite_df['bind'] = 0

cache_rewrite_df = whamm_rewrite_df('cache-sim', True)
cache_rewrite_df['base bind'] = 0
cache_rewrite_df['bind'] = 0

icount_rewrite_df = whamm_rewrite_df('icount', False)
icount_rewrite_df['base bind'] = 0
icount_rewrite_df['bind'] = 0

# Pin data
# the experiment names are:
# - base-run: wasm2c to native
# - base-run0: wasm2c to native on the version that always returns 0
# - base-run-pin: wasm2c to native through pin but with no pintool
# - base-run0-pin: wasm2c to native on the version that always returns 0 through pin but with no pintool
# - pin: using pin with a pintool
# - pin-ret0 : using pin with a pintool on the version that always returns 0
UNINSTR = 'base-run'
SPEC_NOTOOL = 'base-run-pin'
SPEC_EMPTY_TOOL = 'pin-ret0'
SPEC_FULL_TOOL = 'pin'

pintool_names = {
    'icount': 'inscount0.so',
    'imix': 'catmix.so',
    'cache-sim': 'dcache.so',
    'mem-access': 'pinatrace.so',
}

polybench_pin_df = df[(df['config:run_mode'] == 'pin') & (df['benchmark:suite'] == SUITE)]
baseline_polybench_mach_df = polybench_pin_df[(polybench_pin_df['config:experiment'] == UNINSTR)]

def pin_df(mon):
    # Monitor data, polybench data!
    pintool = pintool_names[mon]
    monitor_polybench_df = polybench_pin_df[polybench_pin_df['config:monitor'] == pintool]

    new_df_rows = []
    for benchmark_name in monitor_polybench_df['benchmark:name'].unique():
        try:
            baseline_data = baseline_polybench_jit_df[baseline_polybench_jit_df['benchmark:name'] == f"{benchmark_name}.wasm"]
            base_jit = baseline_data[MEAN].values[0]
        except:
            print(f"[{benchmark_name}] skipping, no baseline data")
            continue
        print(f"[{benchmark_name}] success, found data")


        pin_data = polybench_pin_df[polybench_pin_df['benchmark:name'] == benchmark_name]

        base_uninstr = baseline_polybench_mach_df[baseline_polybench_mach_df['benchmark:name'] == benchmark_name][MEAN].values[0]
        base_notool = pin_data[pin_data['config:experiment'] == SPEC_NOTOOL][MEAN].values[0]
        base_instr_empty = pin_data[(pin_data['config:monitor'] == pintool) & (pin_data['config:experiment'] == SPEC_EMPTY_TOOL)][MEAN].values[0]

        # Includes bind/instr/report times
        pin_instr_full = pin_data[(pin_data['config:monitor'] == pintool) & (pin_data['config:experiment'] == SPEC_FULL_TOOL)][MEAN].values[0]
        # The base bind time for pin
        pin_bind_core = base_notool - base_uninstr
        # The bind time for the pintool
        pin_bind_tool = max(0, base_instr_empty - base_uninstr - pin_bind_core)
        # The instrumentation time for the pintool
        pin_instr = max(0, pin_instr_full - pin_bind_core - pin_bind_tool)

        new_df_rows.append({
            'suite': SUITE,
            'benchmark': benchmark_name,
            'time-jit': base_jit,
            'base bind': pin_bind_core,
            'bind': pin_bind_tool,
            'instr': pin_instr,
            'transfer': 0, # cannot be calculated
            'report': 0    # cannot be calculated
        })

    return pd.DataFrame(new_df_rows)

print("collect pin imix")
imix_pin_df = pin_df('imix')
print("collect pin cache")
cache_pin_df = pin_df('cache-sim')
print("collect pin icount")
icount_pin_df = pin_df('icount')

# =======================
# ==== PLOT THE DATA ====
# =======================
print("Plot the data")
print(imix_pin_df)

import matplotlib.pyplot as plt
import pandas as pd


def plot_df(engine, rewrite, pin, ylim, mon_name, txt, include_title=False, include_ylabel=False,
            include_benchmarks=False):
    # Set the desired order of the stack parts (columns)
    ordered_columns = ['base bind', 'bind', 'transfer', 'report', 'instr']
    colors = ['cornflowerblue', 'royalblue', 'mediumseagreen', 'firebrick', 'sandybrown']

    # Create a figure and an axis
    if include_benchmarks:
        fig, ax = plt.subplots(figsize=(21, 5))
    else:
        fig, ax = plt.subplots(figsize=(21, 4))

    # Sort the DataFrame by 'time-jit' in increasing order
    engine_df_sorted = engine.sort_values('time-jit')
    # Reset the index to ensure the first entry is properly handled
    engine_df_sorted.reset_index(drop=True, inplace=True)

    rewrite_df_sorted = rewrite.sort_values('time-jit')
    # Reset the index to ensure the first entry is properly handled
    rewrite_df_sorted.reset_index(drop=True, inplace=True)

    pin_df_sorted = pin.sort_values('time-jit')
    # Reset the index to ensure the first entry is properly handled
    pin_df_sorted.reset_index(drop=True, inplace=True)

    # Plot each dataframe as a stacked bar chart
    engine_df_sorted[ordered_columns].plot(kind='bar', zorder=3, stacked=True, ax=ax, position=0, width=.25,
                                           color=colors, edgecolor='dimgrey', linewidth=.25)
    rewrite_df_sorted[ordered_columns].plot(kind='bar', zorder=3, stacked=True, ax=ax, position=1, width=.25,
                                            color=colors, edgecolor='dimgrey', linewidth=.25)
    pin_df_sorted[ordered_columns].plot(kind='bar', zorder=3, stacked=True, ax=ax, position=-1, width=.25, color=colors,
                                        edgecolor='dimgrey', linewidth=.25)

    # Combine the legends (same legend for both DataFrames)
    handles, labels = ax.get_legend_handles_labels()
    ax.legend(handles, ordered_columns, loc='upper left')

    # Setting y-axis to logarithmic scale (base 10)
    # ax.set_yscale('log')
    ax.set_ylim(0, ylim)

    # Add extra buffer at the end of the x-axis
    # Set x-axis limits to add extra space after the last bar
    ax.set_xlim(0.5, len(pin_df_sorted))  # Adjust the limits to create buffer space

    # Set custom x-axis labels
    print(engine_df_sorted['benchmark'])
    if include_benchmarks:
        ax.set_xticklabels(engine_df_sorted['benchmark'], fontsize=12, rotation=45)  # Set the x-tick labels
        plt.xlabel('Benchmark', fontweight='bold', fontsize=17)
    else:
        ax.set_xticklabels([])

        # Add labels for total values at the top of each stacked bar
    # Get current y-axis limits
    ymin, ymax = ax.get_ylim()
    # Add labels for total values at the top of each stacked bar, only for bars off the ylim

    for i, container in enumerate(ax.containers):
        curr_x = 0
        total_height = 0
        for bar in container:
            if curr_x == bar.get_x():
                # Calculate the total height of the stacked bar
                total_height = bar.get_height() + (
                    bar.get_y() if bar.get_y() > 0 else 0)  # total height including y offset
            else:
                # we've moved to the next bar, add text first!
                if total_height > ymax:
                    # Only add label if the bar exceeds the current y-limits
                    # Place label above the y-axis limits
                    ax.text(curr_x + bar.get_width() - .18, ymax - .5,  # Position label just above ymax
                            f'{total_height:.1f}', ha='center', va='center', rotation=270,
                            fontsize=10)  # Add labels for total values at the top of each stacked bar, only for bars off the ylim
                curr_x = bar.get_x();
                total_height = bar.get_height() + (bar.get_y() if bar.get_y() > 0 else 0)

        if total_height > ymax:
            # Only add label if the bar exceeds the current y-limits
            # Place label above the y-axis limits
            ax.text(curr_x + bar.get_width() - .18, ymax - .5,  # Position label just above ymax
                    f'{total_height:.1f}', ha='center', va='center', rotation=270,
                    fontsize=10)  # Add labels for total values at the top of each stacked bar, only for bars off the ylim

    # for i, container in enumerate(ax.containers):
    #     for bar in container:
    #         # Calculate the total height of the stacked bar
    #         total_height = bar.get_height() + (bar.get_y() if bar.get_y() > 0 else 0)  # total height including y offset

    #         # Only add label if the bar exceeds the current y-limits
    #         if total_height > ymax:
    #             # Place label above the y-axis limits
    #             ax.text(bar.get_x() + bar.get_width() - .1, ymax - .3,  # Position label just above ymax
    #                     f'{total_height:.1f}', ha='center', va='center', rotation=90, fontsize=10)# Add labels for total values at the top of each stacked bar, only for bars off the ylim
    #             continue

    # Adding labels and title
    if include_benchmarks:
        fig.text(1.02, 0.6, f'{mon_name}', ha='right', va='center', fontsize=17, fontweight='bold', rotation=270)
    else:
        fig.text(1.02, 0.5, f'{mon_name}', ha='right', va='center', fontsize=17, fontweight='bold', rotation=270)
    if include_ylabel:
        fig.text(-0.02, 0.5, f'Absolute Overhead (seconds)', ha='left', va='center', fontsize=17, fontweight='bold',
                 rotation=90)
    else:
        fig.text(-0.02, 0.5, f'   ', ha='left', va='center', fontsize=17, fontweight='bold', rotation=90)
    plt.grid(True, axis='y', zorder=0)
    # create second y axis label
    # ax1 = ax.twinx()
    # ax1.set_ylim(ax.get_ylim())  # Set the same y-limits
    if include_title:
        fig.text(0.5, 1.02, f'Whamm vs. Pin', ha='center', va='top', fontsize=20, fontweight='bold')
    # plt.title(f'Ω vs. Pin ({mon_name})')

    # Add a text box with min/max values to the upper-left corner
    ax.text(0.1, 0.93, txt, transform=ax.transAxes, fontsize=12,
            verticalalignment='top', horizontalalignment='left',
            bbox=dict(facecolor='white', alpha=0.7, edgecolor='black', boxstyle='round,pad=0.5'))

    # Automatically adjust the layout for better spacing
    plt.tight_layout()
    plt.savefig(f"{OUTDIR_PLOTS}/whamm-vs-pin-{mon_name}.pdf", dpi=400, bbox_inches='tight')

def min_max(target_df):
    cols = ['base bind', 'bind', 'transfer', 'report', 'instr']
    row_sums = target_df[cols].sum(axis=1)

    return row_sums.min(), row_sums.max()

# Plot Imix Monitor
print(imix_pin_df)
engine_minmax = min_max(imix_engine_df)
imix_engine_min = engine_minmax[0]
imix_engine_max = engine_minmax[1]
engine_str = f'$\\it{{wei}}$, inlined {imix_engine_min:.2f}-{imix_engine_max:.2f}s'

rewrite_minmax = min_max(imix_rewrite_df)
imix_rewrite_min = rewrite_minmax[0]
imix_rewrite_max = rewrite_minmax[1]
rewrite_str = 'Whamm rewriting, jit: ' + f'{imix_rewrite_min:.2f}-{imix_rewrite_max:.2f}s'

plot_df(imix_engine_df, imix_rewrite_df, imix_pin_df, 6, 'imix', f'{rewrite_str}    {engine_str}    Pin: 0.56-0.84s', include_title=True)

# Plot icount Monitor
engine_minmax = min_max(icount_engine_df)
icount_engine_min = engine_minmax[0]
icount_engine_max = engine_minmax[1]
engine_str = f'$\\it{{wei}}$, inlined {icount_engine_min:.2f}-{icount_engine_max:.2f}s'

rewrite_minmax = min_max(icount_rewrite_df)
icount_rewrite_min = rewrite_minmax[0]
icount_rewrite_max = rewrite_minmax[1]
rewrite_str = 'Whamm rewriting, jit: ' + f'{icount_rewrite_min:.2f}-{icount_rewrite_max:.2f}s'

plot_df(icount_engine_df, icount_rewrite_df, icount_pin_df, 2.5, 'icount', f'{rewrite_str}    {engine_str}    Pin: 0.20-0.98s', include_ylabel=True)

# Plot cache Monitor
engine_minmax = min_max(cache_engine_df)
cache_engine_min = engine_minmax[0]
cache_engine_max = engine_minmax[1]
engine_str = f'$\\it{{wei}}$, inlined {cache_engine_min:.2f}-{cache_engine_max:.2f}s'

rewrite_minmax = min_max(cache_rewrite_df)
cache_rewrite_min = rewrite_minmax[0]
cache_rewrite_max = rewrite_minmax[1]
rewrite_str = 'Whamm rewriting, jit: ' + f'{cache_rewrite_min:.2f}-{cache_rewrite_max:.2f}s'

plot_df(cache_engine_df, cache_rewrite_df, cache_pin_df, 6, 'cache', f'{rewrite_str}    {engine_str}    Pin: 0.26-2.95s', include_benchmarks=True)
