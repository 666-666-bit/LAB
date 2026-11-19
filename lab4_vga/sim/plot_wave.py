import pandas as pd
import matplotlib.pyplot as plt
import os

os.makedirs('../doc', exist_ok=True)
df = pd.read_csv('vga_wave.csv')
df.columns = df.columns.str.strip()

fig, axes = plt.subplots(4, 1, figsize=(10, 8), sharex=True)

# 1. key_in 原始抖动按键输入
axes[0].plot(df['Time'], df['tb_vga_top.key_in'], color='black', drawstyle='steps-post')
axes[0].set_ylabel('key_in (raw)')
axes[0].set_ylim(-0.2, 1.2)

# 2. 消抖输出脉冲 key_flag
axes[1].plot(df['Time'], df['tb_vga_top.dut.key_flag'], color='blue', drawstyle='steps-post')
axes[1].set_ylabel('key_flag')
axes[1].set_ylim(-0.2, 1.2)

# 3. 状态机当前状态 cur_state
axes[2].plot(df['Time'], df['tb_vga_top.dut.cur_state'], color='purple', drawstyle='steps-post')
axes[2].set_ylabel('cur_state[1:0]')
axes[2].set_yticks([0, 1, 2])
axes[2].set_yticklabels(['0:BARS', '1:MUST', '2:END'])

# 4. 复位信号 sys_rst_n
axes[3].plot(df['Time'], df['tb_vga_top.sys_rst_n'], color='red', drawstyle='steps-post')
axes[3].set_ylabel('sys_rst_n')
axes[3].set_ylim(-0.2, 1.2)
axes[3].set_xlabel('Time (ns)')

for ax in axes:
    ax.grid(True, linestyle='--', alpha=0.5)

plt.tight_layout()
plt.savefig('../doc/fsm_transition_waveform.png', dpi=300)
print("时序仿真图已生成: ../doc/fsm_transition_waveform.png")
