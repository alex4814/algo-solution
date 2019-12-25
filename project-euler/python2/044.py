def is_pentagonal(x):
    import math
    n = (math.sqrt(1+24*x)+1)/6
    return n == int(n) and n > 0

def p(n):
    return n*(3*n-1)/2

n = 2
pentagonals = {1}
found = False
while not found:
    m = p(n)
    for x in pentagonals:
        if m - x in pentagonals:
            if is_pentagonal(m + x):
                print m - x
                found = True
                break
    pentagonals.add(m)
    n += 1

