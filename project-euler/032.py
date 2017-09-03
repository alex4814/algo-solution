from itertools import permutations

pandigitals = set()

def check(p, i, j):
    a = int(''.join(p[:i]))
    b = int(''.join(p[i:j]))
    c = int(''.join(p[j:]))
    if a * b == c:
        pandigitals.add(c)

g = permutations('123456789')
for p in g:
    check(p, 1, 5)
    check(p, 2, 5)
print sum(pandigitals)

