import sys
import pandas as pd
from vcdvcd import VCDVCD

if len(sys.argv) != 3:
    print("Usage: python3 vcd2csv.py <input.vcd> <output.csv>")
    sys.exit()

vcd_path = sys.argv[1]
csv_path = sys.argv[2]

try:
    vcd = VCDVCD(vcd_path)
except Exception as e:
    print(f"Error reading VCD: {e}")
    sys.exit()

all_time = set()
signals = {}

for ref in vcd.references_to_ids.keys():
    signals[ref] = vcd[ref].tv
    for t, _ in signals[ref]:
        all_time.add(t)

all_time = sorted(list(all_time))
df = pd.DataFrame({'Time': all_time})

for ref, tv in signals.items():
    vals = []
    idx = 0
    cur = '0'
    for t in all_time:
        if idx < len(tv) and tv[idx][0] == t:
            cur = tv[idx][1]
            idx += 1
        vals.append(cur)
    df[ref] = vals

df.to_csv(csv_path, index=False)
print(f"Success: {vcd_path} -> {csv_path}")
