import sys
import argparse
import pandas as pd
from vcdvcd import VCDVCD


def parse_signal_value(val_str):
    if val_str is None:
        return None
    val_str = str(val_str).strip().lower()
    
    if 'x' in val_str or 'z' in val_str:
        return val_str
    
    try:
        if val_str.startswith('b'):
            return int(val_str[1:], 2)
        elif len(val_str) > 1 and all(c in '01' for c in val_str):
            return int(val_str, 2)
        else:
            return int(val_str)
    except ValueError:
        return val_str


def vcd_to_csv(vcd_file, csv_file, filter_signals=None):
    try:
        vcd = VCDVCD(vcd_file)
    except Exception as e:
        sys.exit(1)

    all_signals = vcd.signals
    if not all_signals:
        sys.exit(1)

    selected_signals = []
    if filter_signals:
        for sig in all_signals:
            short_name = sig.split('.')[-1].split('[')[0]
            if short_name in filter_signals or sig in filter_signals:
                selected_signals.append(sig)
    else:
        selected_signals = all_signals

    if not selected_signals:
        sys.exit(1)

    timestamps = set()
    signal_tv_dict = {}

    for sig in selected_signals:
        tv_list = vcd[sig].tv
        signal_tv_dict[sig] = tv_list
        for t, _ in tv_list:
            timestamps.add(t)

    sorted_times = sorted(timestamps)

    data_rows = []
    ptrs = {sig: 0 for sig in selected_signals}
    current_values = {sig: None for sig in selected_signals}
    col_names = ['time'] + [sig.split('.')[-1].split('[')[0] for sig in selected_signals]

    for t in sorted_times:
        row = [t]
        for sig in selected_signals:
            tv = signal_tv_dict[sig]
            idx = ptrs[sig]
            while idx < len(tv) and tv[idx][0] <= t:
                current_values[sig] = tv[idx][1]
                idx += 1
            ptrs[sig] = idx
            row.append(parse_signal_value(current_values[sig]))
        data_rows.append(row)

    df = pd.DataFrame(data_rows, columns=col_names)
    df.to_csv(csv_file, index=False)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("vcd_file")
    parser.add_argument("csv_file")
    parser.add_argument("-s", "--signals", nargs="+", default=None)

    args = parser.parse_args()
    vcd_to_csv(args.vcd_file, args.csv_file, args.signals)


if __name__ == "__main__":
    main()