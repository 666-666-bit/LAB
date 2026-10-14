from vcdvcd import VCDVCD
import matplotlib.pyplot as plt

vcd = VCDVCD('comparator_tb.vcd')

signals = [
    ('comparator_1bit_tb.key_a', 'key_a\n(A, Active-Low)'),
    ('comparator_1bit_tb.key_b', 'key_b\n(B, Active-Low)'),
    ('comparator_1bit_tb.led_less', 'led_less\n(A<B, Active-Low)'),
    ('comparator_1bit_tb.led_equal', 'led_equal\n(A=B, Active-Low)'),
    ('comparator_1bit_tb.led_greater', 'led_greater\n(A>B, Active-Low)')
]

endtime = 100 

fig, axes = plt.subplots(len(signals), 1, figsize=(10, 8), sharex=True)

for idx, (sig_name, label) in enumerate(signals):
    tv = vcd[sig_name].tv
    times = [t for t, v in tv] + [endtime]
    vals = [int(v) for t, v in tv] + [int(tv[-1][1])]

    color = '#1f77b4' if idx < 2 else '#d62728'
    axes[idx].step(times, vals, where='post', linewidth=2.5, color=color)
    axes[idx].set_ylabel(label, rotation=0, labelpad=50, va='center', fontsize=10, fontweight='bold')
    axes[idx].set_yticks([0, 1])
    axes[idx].set_ylim(-0.2, 1.2)
    axes[idx].grid(True, linestyle='--', alpha=0.6)

axes[-1].set_xlabel('Time (ns)', fontsize=12, fontweight='bold')
axes[-1].set_xticks(range(0, endtime + 1, 20))
plt.suptitle('Functional Simulation Waveforms of 1-bit Comparator', fontsize=14, fontweight='bold')
plt.tight_layout()
plt.savefig('Comparator_waveform.png', dpi=300)
print("Waveform successfully saved as Comparator_waveform.png!")
