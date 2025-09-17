import matplotlib.pyplot as plt
import matplotlib.patches as patches

def draw_memory_diagram():
    fig, ax = plt.subplots(figsize=(10, 8))

    # Memory block for patterns[]
    ax.text(0.5, 1.0, "patterns[] @ 0x3000", fontsize=12, fontweight='bold')
    for i, addr, pattern_addr in zip(range(3), [0x3000, 0x3004, 0x3008], [0x2000, 0x2100, 0x2200]):
        y = 0.9 - i * 0.1
        ax.add_patch(patches.Rectangle((0.1, y), 0.8, 0.08, edgecolor='black', facecolor='lightblue'))
        ax.text(0.15, y + 0.03, f"patterns[{i}] = 0x{pattern_addr:X}", fontsize=10)
        ax.text(0.6, y + 0.03, f"→ pattern{i}[0]", fontsize=10)

    # pattern0
    base_y = 0.55
    ax.text(0.5, base_y + 0.1, "pattern0 @ 0x2000", fontsize=12, fontweight='bold')
    for i in range(5):
        y = base_y - i * 0.08
        addr = 0x2000 + i * 4
        ax.add_patch(patches.Rectangle((0.1, y), 0.8, 0.07, edgecolor='black', facecolor='lightgreen'))
        ax.text(0.15, y + 0.02, f"pattern0[{i}] @ 0x{addr:X}", fontsize=9)
        if i == 0:
            ax.text(0.5, y + 0.02, "{false, true, 3000}", fontsize=9)

    # pattern1
    base_y = 0.1
    ax.text(0.5, base_y + 0.1, "pattern1 @ 0x2100", fontsize=12, fontweight='bold')
    for i in range(5):
        y = base_y - i * 0.08
        addr = 0x2100 + i * 4
        ax.add_patch(patches.Rectangle((0.1, y), 0.8, 0.07, edgecolor='black', facecolor='khaki'))
        ax.text(0.15, y + 0.02, f"pattern1[{i}] @ 0x{addr:X}", fontsize=9)
        if i == 2:
            ax.text(0.5, y + 0.02, "{true, false, 500}", fontsize=9)

    ax.set_xlim(0, 1)
    ax.set_ylim(-0.4, 1.05)
    ax.axis('off')
    plt.tight_layout()
    plt.show()

draw_memory_diagram()

