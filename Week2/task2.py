# coding=UTF-8

# square_roots.py

import math

print("Let's calculate some square roots!")

n = input("Gibe number: ")

print(math.sqrt(float(n)) if n.isnumeric() else "that's not a number!" )