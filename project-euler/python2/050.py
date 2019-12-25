from array import array
from operator import mul

MAX = 1000000
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

print 'Below {}, there are {} primes.'.format(MAX, len(primes))
primes_set = set(primes)

length = 21
while True:
    if length > len(primes):
        break
    cursor = length
    total = sum(primes[:cursor])
    if total > MAX:
        break
    while cursor < len(primes):
        if total > MAX:
            break
        if total in primes_set:
            numbers = primes[cursor-length: cursor]
            print 'Sum of consecutive primes (of length {}) is also prime {}.'.format(length, total)
        total = total - primes[cursor-length] + primes[cursor]
        cursor += 1
    length += 1

