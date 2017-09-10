import math

def is_pentagonal(p):
    n = (math.sqrt(1+24*p)+1)/6
    return n == int(n) and n > 0

def is_hexagonal(h):
    n = (math.sqrt(1+8*h)+1)/4
    return n == int(n) and n > 0

n = 286

while True:
    t = n * (n + 1) / 2
    if is_pentagonal(t) and is_hexagonal(t):
        break
    n += 1
print t
