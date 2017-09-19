# [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
# whose sum is 409114

from itertools import permutations
import math


def is_prime(y):
    if y % 2 == 0:
        return False
    u = int(math.sqrt(float(y)))
    for p in xrange(3, u+1, 2):
        if y % p == 0:
            return False
    return True

pandigitals = []
for n in xrange(1, 10):
    x = ''.join(str(c) for c in xrange(1, n+1))
    for p in permutations(x):
        y = int(''.join(p))
        if is_prime(y):
            pandigitals.append(y)

print max(pandigitals)
