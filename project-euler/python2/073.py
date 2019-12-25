from fractions import gcd

N = 12001
lo = (1, 3)
hi = (1, 2)

total = 0
for d in xrange(2, N):
    n_lo = (lo[0] * d + lo[1] - 1) / lo[1]
    if (n_lo, d) == lo:
        n_lo += 1
    n_hi = (hi[0] * d + hi[1] - 1) / hi[1]
    for n in xrange(n_lo, n_hi):
        if gcd(n, d) == 1:
            total += 1
print total

