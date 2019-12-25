from array import array
import bisect

MAX = 100
is_composite = {}
primes = array('l')

for n in xrange(2, MAX):
    if not is_composite.setdefault(n, False):
        primes.append(n)
    for p in primes:
        m = p * n
        if m >= MAX:
            break
        is_composite[m] = True
        if n % p == 0:
            break

primes.insert(0, -1)

f = []
for i in xrange(MAX):
    x = bisect.bisect(primes, i)
    row = [0] * x
    if primes[x-1] == i:
        row[x-1] = 1
    f.append(row)

for i in xrange(4, MAX):
    i_ = bisect.bisect(primes, i)
    for j in xrange(1, i_):
        d = i - primes[j]
        for k in xrange(j):
            if k+1 >= len(f[d]):
                break
            f[i][j] += f[d][k+1]


def ways_of(n):
    ways = 0
    j_ = bisect.bisect(primes, n)
    for j in xrange(j_):
        ways += f[n][j]
    return ways

for n in xrange(10, MAX):
    if ways_of(n) > 5000:
        break
print n 

