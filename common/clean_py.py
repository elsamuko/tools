#!/usr/bin/env python3
# remove docstring comments from python sources
# https://stackoverflow.com/a/59271643

import ast
import sys
import os


def clean(filename: str):

    if not os.path.exists(filename):
        print(f"{filename} does not exist")
        return

    with open(filename, "r") as f:
        parsed = ast.parse(f.read())

        for node in ast.walk(parsed):
            if not isinstance(node, (ast.FunctionDef, ast.ClassDef, ast.AsyncFunctionDef)):
                continue
            if not len(node.body):
                continue
            if not isinstance(node.body[0], ast.Expr):
                continue
            if not hasattr(node.body[0], 'value') or not isinstance(node.body[0].value, ast.Constant):
                continue
            node.body.pop(0)

        out = ast.unparse(parsed)

    with open(filename, "w") as f:
        f.write(out + "\n")
    print(f"Cleaned {filename}")


if __name__ == "__main__":
    filename = sys.argv[1]
    clean(filename)
