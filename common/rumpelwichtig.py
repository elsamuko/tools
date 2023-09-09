#!/usr/bin/env python3
# convert input to Rumpelwichte language

import random
import sys

normal = " ".join(sys.argv[1:])

# lowercase
normal = normal.replace("o", "u")
normal = normal.replace("st", "t")
# replace g -> d, except for ng
pos = normal.find("g")
while pos != -1:
    if normal[pos-1] != "n":
        normal = normal[:pos] + "d" + normal[pos + 1:]
    pos = normal.find("g", pos+1)


# uppercase
normal = normal.replace("O", "U")
normal = normal.replace("St", "T")
normal = normal.replace("G", "D")

if random.random() < 0.5:
    normal = normal.replace(".", ". Pfui pfui.")

print(normal)
