import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("sim-wave/counter.csv")

fig, axes = plt.subplots(4, 1, sharex=True, figsize=(10, 6))

axes[0].step(df['time'], df['sys_clk'], where='post', color='black')
axes[0].set_ylabel('sys_clk')
axes[0].set_ylim(-0.2, 1.2)

axes[1].step(df['time'], df['sys_rst_n'], where='post', color='blue')
axes[1].set_ylabel('sys_rst_n')
axes[1].set_ylim(-0.2, 1.2)

axes[2].step(df['time'], df['cnt'], where='post', color='darkgreen')
axes[2].set_ylabel('cnt')

axes[3].step(df['time'], df['led_out'], where='post', color='red')
axes[3].set_ylabel('led_out')
axes[3].set_ylim(-0.2, 1.2)
axes[3].set_xlabel('Time (ns)')

for ax in axes:
    ax.grid(True, linestyle='--', alpha=0.5)

plt.tight_layout()
plt.savefig("waveform_report.png", dpi=300)