MAX = 10000000
phi = [0] * MAX


def get_phi(n):
    for i in xrange(0, MAX):
        phi[i] = i
    for i in xrange(2, MAX):
        if phi[i] == i:
            for j in xrange(i, MAX, i):
                phi[j] = phi[j] * (i-1) / i


def is_permutation(x, y):
    x, y = str(x), str(y)
    if len(x) != len(y):
        return False
    return sorted(x) == sorted(y)


get_phi(MAX)
n, r = 1, 100000.
for i in xrange(2, MAX):
    if not is_permutation(i, phi[i]):
        continue
    r_ = float(i) / phi[i]
    if r_ < r:
        r = r_
        n = i
print n, r
