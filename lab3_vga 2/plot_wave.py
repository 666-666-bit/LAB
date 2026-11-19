import pandas as pd
import matplotlib.pyplot as plt
import os

# 确保 doc 目录存在
os.makedirs('doc', exist_ok=True)

# 自动匹配当前目录或 sim/ 下的 csv
csv_path = 'vga_wave.csv' if os.path.exists('vga_wave.csv') else 'sim/vga_wave.csv'
df = pd.read_csv(csv_path)

# 截取前 35000 ns 窗口（包含完整的 32us 行同步周期）
df_window = df[df['Time'] <= 35000]

# 列名去空格，防止匹配异常
df_window.columns = df_window.columns.str.strip()

fig, axes = plt.subplots(3, 1, figsize=(10, 6), sharex=True)

# 1. 查找并绘制 hsync
hsync_col = [c for c in df_window.columns if 'hsync' in c]
if hsync_col:
    axes[0].step(df_window['Time'], df_window[hsync_col[0]], where='post', color='blue')
axes[0].set_ylabel('hsync')
axes[0].set_ylim(-0.2, 1.2)

# 2. 查找并绘制 vsync
vsync_col = [c for c in df_window.columns if 'vsync' in c]
if vsync_col:
    axes[1].step(df_window['Time'], df_window[vsync_col[0]], where='post', color='green')
axes[1].set_ylabel('vsync')
axes[1].set_ylim(-0.2, 1.2)

# 3. 查找并绘制 rgb
rgb_col = [c for c in df_window.columns if 'rgb' in c]
if rgb_col:
    axes[2].plot(df_window['Time'], df_window[rgb_col[0]], color='red')
axes[2].set_ylabel('rgb[15:0]')
axes[2].set_xlabel('Time (ns)')

for ax in axes:
    ax.grid(True, linestyle='--', alpha=0.6)

plt.tight_layout()
plt.savefig('doc/vga_simulation_waveform.png', dpi=300)
print("波形图已成功生成: doc/vga_simulation_waveform.png")
