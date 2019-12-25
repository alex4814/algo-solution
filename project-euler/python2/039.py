def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

solutions = [0] * 1001

# Enumerate all possible length sides a, b where a < b < c, 
# according to Euclid's formula to generate Pythagorean triplets
for t in xrange(3, 1000):
    for s in xrange(t+2, 1000):
        if gcd(s, t) != 1:
            continue
        a = s * t
        b = (s * s - t * t) / 2
        c = (s * s + t * t) / 2

        p = a + b + c
        f = 1
        while p * f <= 1000:
            solutions[p * f] += 1
            f += 1

r = max(solutions)
print [i for i, v in enumerate(solutions) if v == r]
