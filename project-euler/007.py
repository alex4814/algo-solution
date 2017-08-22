from array import array

MAX = 142857
is_composite = {}
primes = array('l')

for n in xrange(2, MAX):
    if not is_composite.setdefault(n, False):
        primes.append(n)
        if len(primes) > 10000:
            break
    for p in primes:
        m = p * n
        if m >= MAX:
            break
        is_composite[m] = True
        if n % p == 0:
            break

print len(primes), primes[-1]
