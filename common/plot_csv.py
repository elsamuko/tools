#!/usr/bin/env python3
# simple csv plotter

import sys
import pandas
from pathlib import Path
import matplotlib.pyplot as plt

if len(sys.argv) == 1:
    print(f"Usage: {sys.argv[0]} data.csv")
    sys.exit(1)

filename = Path(sys.argv[1])

frame = pandas.read_csv(filename, comment="#")
frame.plot()

image = f"{filename.stem}.png"
plt.savefig(image)
print(f"Plotted to {image}")
