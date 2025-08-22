import pandas as pd

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

    df = opts.astype(column_dtypes)

    # Check that there are no errors in the data set
    errored = opts[opts['run_errored'] == True]
    assert errored.empty, 'We had some errors!'

    return df

def make_thirds_int(all_df):
    # Split into 3 equally sized groups (tertiles)
    all_df['group'] = pd.qcut(all_df["time-int"], q=3, labels=[1, 2, 3])
    return all_df

def make_thirds_jit(all_df, cols):
    # Split into 3 equally sized groups (tertiles)
    all_df['group'] = pd.qcut(all_df["time-jit"], q=3, labels=[1, 2, 3])
    all_df = all_df.rename(columns = cols)
    return all_df
