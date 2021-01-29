#!/usr/bin/env python3

import sys


def usage():
    print("Usage")
    print("    tohex.py 0x123")
    print("    tohex.py 0b101")
    print("    tohex.py 12345")
    print("")
    exit(0)


def printDEC(parsed):
    print("DEC %i" % parsed)


def printHEX(parsed):
    print('HEX 0x%x' % parsed)


def printBIN(parsed):
    print('BIN 0b{:b}'.format(parsed))


if len(sys.argv) != 2:
    usage()

arg = sys.argv[1]

if(arg.startswith("0x")):
    parsed = int(arg, 16)
elif(arg.startswith("0b")):
    parsed = int(arg, 2)
else:
    parsed = int(arg)

printDEC(parsed)
printHEX(parsed)
printBIN(parsed)
