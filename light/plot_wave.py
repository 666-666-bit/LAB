import pandas as pd
import matplotlib.pyplot as plt

csv_filename = 'running_light.csv' 
try:
    df = pd.read_csv(csv_filename)
except FileNotFoundError:
    print("Error: File not found.")
    exit()

time_col = df.columns[0]
rst_col = 'tb_running_light.sys_rst_n' 
cnt_col = 'tb_running_light.u_running_light.cnt[24:0]'
led_col = 'tb_running_light.led_out[3:0]'

try:
    time_data = df[time_col]
    rst_data = df[rst_col]
    cnt_data = df[cnt_col]
    led_data = df[led_col]
except KeyError as e:
    print(f"KeyError: {e}")
    print("Available columns are:")
    print(df.columns.tolist())
    exit()

def clean_binary(val):
    if isinstance(val, str):
        val = val.replace('b', '').replace('x', '0').replace('z', '0')
        try:
            return int(val, 2)
        except ValueError:
            return 0
    return val

cnt_data = cnt_data.apply(clean_binary)
led_data = led_data.apply(clean_binary)

fig, axs = plt.subplots(3, 1, figsize=(10, 8), sharex=True)

axs[0].step(time_data, rst_data, where='post', color='#d62728', linewidth=2)
axs[0].set_ylabel('sys_rst_n', fontsize=12)
axs[0].set_ylim(-0.2, 1.2)
axs[0].set_yticks([0, 1])
axs[0].grid(True, linestyle='--', alpha=0.6)

axs[1].step(time_data, cnt_data, where='post', color='#1f77b4', linewidth=2)
axs[1].set_ylabel('cnt (Decimal)', fontsize=12)
axs[1].grid(True, linestyle='--', alpha=0.6)

axs[2].step(time_data, led_data, where='post', color='#2ca02c', linewidth=2)
axs[2].set_ylabel('led_out (Decimal)', fontsize=12)
axs[2].set_xlabel('Time (ns)', fontsize=12)
axs[2].grid(True, linestyle='--', alpha=0.6)

plt.suptitle('Running Light Verification Waveform', fontsize=14, fontweight='bold')
plt.tight_layout()

plt.savefig('waveform_report.pdf', format='pdf', dpi=300)
plt.savefig('waveform_report.png', format='png', dpi=300)
print("Success: waveform_report.pdf and waveform_report.png generated.")
