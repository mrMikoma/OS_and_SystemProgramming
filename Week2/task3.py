from ctypes import *

libc = CDLL("libc.so.6")

libc.printf("hello everybody\n".encode('ascii'))

import sys

def printf(format, *args):

    sys.stdout.write(format % args)

printf("moikka %s\n", "maailma")