def clean(df, timeout_s):
    column_dtypes = {
        "run_time:mean": "float64",
        "wiz_metrics_main:time_us": "float64",
        "wiz_metrics_whamm:bind_time_us": "float64",
        "wiz_metrics_whamm:report_time_us": "float64",
        "run_cmd": "string"
    }
    opts = df[[
        "run_errored",
        "config:run_mode", "config:monitor", "config:experiment", "config:special",
        "benchmark:suite", "benchmark:name",
        "run_time:mean",
        "wiz_metrics_main:time_us", "wiz_metrics_whamm:bind_time_us", "wiz_metrics_whamm:report_time_us",
        "run_cmd", "run_timed_out"
    ]]
    opts = opts[opts["run_errored"] == False]
    opts["run_time:mean"] = opts["run_time:mean"].replace("NONE", timeout_s)
    opts["run_time:mean"] = opts["run_time:mean"].fillna(timeout_s)

    timeout_us = timeout_s * 1_000_000
    opts["wiz_metrics_main:time_us"] = opts["wiz_metrics_main:time_us"].replace("NONE", timeout_us)
    opts["wiz_metrics_main:time_us"] = opts["wiz_metrics_main:time_us"].fillna(timeout_us)

    opts["wiz_metrics_whamm:bind_time_us"] = opts["wiz_metrics_whamm:bind_time_us"].replace("NONE", 0)
    opts["wiz_metrics_whamm:bind_time_us"] = opts["wiz_metrics_whamm:bind_time_us"].fillna(0)

    opts["wiz_metrics_whamm:report_time_us"] = opts["wiz_metrics_whamm:report_time_us"].replace("NONE", 0)
    opts["wiz_metrics_whamm:report_time_us"] = opts["wiz_metrics_whamm:report_time_us"].fillna(0)

    opts = opts[opts['config:experiment'].isin(['whamm_engine', 'base-run', 'whamm_rewrite'])]
    df = opts.astype(column_dtypes)

    # Check that there are no errors in the data set
    errored = opts[opts['run_errored'] == True]
    assert errored.empty, 'We had some errors!'

    return df

def group_int(x):
    if x["suite"] == "polybench":
        if x["time-int"] < 250_000:
            return 1
        elif x["time-int"] < 800_000:
            return 2
        else:
            return 3
    else:
        if x["time-int"] < 10_000:
            return 4
        if x["time-int"] < 1.7e6:
            return 5
        return 6

def make_thirds_int(all_df):
    all_df['group'] = all_df.apply(group_int, axis=1)
    all_df = all_df.rename(columns={
        '$\\it{wei}$, int-rt-int': '$\\it{wei}$, int-rt-int',
        '$\\it{wei}$, int-rt-jit': '$\\it{wei}$, int-rt-jit',
        '$\\it{wei}$, int-tramp-int': '$\\it{wei}$, int-tramp-int',
        '$\\it{wei}$, int-tramp-jit': '$\\it{wei}$, int-tramp-jit',
        'Whamm rewriting, int': 'Whamm rewriting, int'
    })
    return all_df

def group_jit_s(x):
    if x["suite"] == "r3":
        if x["time-jit"] < 0.30:
            return 4
        elif x["time-jit"] < 0.79:
            return 5
        else:
            return 6
    else:
        if x["time-jit"] < 0.030:
            return 1
        elif x["time-jit"] < 0.06:
            return 2
        else:
            return 3

def group_jit_us(x):
    if x["suite"] == "r3":
        if x["time-jit"] < 1_000:
            return 4
        elif x["time-jit"] < 120_000:
            return 5
        else:
            return 6
    else:
        if x["time-jit"] < 20_000:
            return 1
        elif x["time-jit"] < 50_000:
            return 2
        else:
            return 3

def make_thirds_jit(all_df, in_s, cols):
    if in_s:
        all_df['group'] = all_df.apply(group_jit_s, axis=1)
    else:
        all_df['group'] = all_df.apply(group_jit_us, axis=1)
    all_df = all_df.rename(columns = cols)
    return all_df
