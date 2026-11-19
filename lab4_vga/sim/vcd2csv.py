import sys
import argparse
import pandas as pd
from vcdvcd import VCDVCD

def main():
    parser = argparse.ArgumentParser(description="Convert VCD to CSV")
    parser.add_argument("-i", "--input", required=True, help="Input VCD file")
    parser.add_argument("-o", "--output", required=True, help="Output CSV file")
    args = parser.parse_args()

    vcd = VCDVCD(args.input)
    
    # 提取时间轴与关注信号
    time_points = set()
    signal_data = {}
    
    for sig in vcd.signals:
        tv = vcd[sig].tv
        signal_data[sig] = dict(tv)
        time_points.update([t for t, _ in tv])
        
    times = sorted(list(time_points))
    df = pd.DataFrame({'Time': times})
    
    for sig, tv_dict in signal_data.items():
        # 按时间步进对齐信号值
        vals = []
        cur_v = None
        for t in times:
            if t in tv_dict:
                cur_v = tv_dict[t]
            vals.append(cur_v)
        df[sig] = vals
        
    df.to_csv(args.output, index=False)
    print(f"转换成功: {args.output}")

if __name__ == '__main__':
    main()
