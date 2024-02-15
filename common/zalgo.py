#!/usr/bin/env python3
# zalgo converter
# via https://gist.github.com/alexmojaki/8a4ba43e66ee78a99b8435e05818a3e3

import sys
import random

marks = list(map(chr, range(768, 879)))


def zalgo_chars(count: int):
    return "".join(random.choices(marks, k=count))


def to_zalgo(input: str) -> str:
    return "".join(
        c + zalgo_chars(int(i / 2)) * c.isalnum() for i, c in enumerate(input)
    )


print(to_zalgo(" ".join(sys.argv[1:])))
