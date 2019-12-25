from array import array
import bisect
import math

MAX = 65500
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

def is_square(n):
    x = int(math.sqrt(float(n)))
    return x * x == n

for n in xrange(35, MAX, 2):
    u = bisect.bisect_left(primes, n)
    if primes[u] == n:
        continue
    written = False
    for i in xrange(u):
        remainder = n - primes[i]
        if is_square(remainder / 2):
            written = True
            break
    if not written:
        break

if written:
    print 'Not found under', MAX
print n 
