MAX = 1000000
is_composite = {}
primes = set()

for n in xrange(2, MAX):
    if not is_composite.setdefault(n, False):
        primes.add(n)
    for p in primes:
        m = p * n
        if m >= MAX:
            break
        is_composite[m] = True
        if n % p == 0:
            break

length = 0
ret = (0, 0)
for a in xrange(-999, 1001):
    for b in xrange(-999, 1001):
        n = 0
        while True:
            m = n * n + a * n + b
            if m not in primes:
                break
            n += 1
        if n - 1 > length:
            length = n - 1
            ret = (a, b)
print ret[0] * ret[1]
