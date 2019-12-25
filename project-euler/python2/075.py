from fractions import gcd

L = 1500000
solutions = {}

# Enumerate all possible length sides a, b where a < c and b < c, 
# according to Euclid's formula to generate Pythagorean triplets
for t in xrange(1, 500000, 2):
    for s in xrange(t+2, 500000, 2):
        if gcd(s, t) != 1:
            continue
        a = s * t
        b = (s * s - t * t) / 2
        c = (s * s + t * t) / 2

        p = a + b + c
        if p > L:
            break
        k = 1
        while p * k <= L:
            solutions.setdefault(p * k, 0)
            solutions[p * k] += 1
            k += 1

print sum(1 for p, v in solutions.iteritems() if p <= L and v == 1)

