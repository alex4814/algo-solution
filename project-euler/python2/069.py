MAX = 1000001
phi = [0] * MAX


def get_phi(n):
    for i in xrange(0, MAX):
        phi[i] = i
    for i in xrange(2, MAX):
        if phi[i] == i:
            for j in xrange(i, MAX, i):
                phi[j] = phi[j] * (i-1) / i


get_phi(MAX)
n, r = 1, 1.
for i in xrange(2, MAX):
    r_ = float(i) / phi[i]
    if r_ > r:
        r = r_
        n = i
print n, r
