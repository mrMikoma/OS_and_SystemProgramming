
# Idea: Stackoverflow: "Sum of Two Integers without using "plus" operator in python"

def bittisumma(a, b):
    while b:
        a, b = (a ^ b), (a & b) << 1

    summa = a

    return summa