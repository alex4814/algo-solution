from array import array

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

primes = set(primes)

def circular(n):
    x = str(n)
    rounds = len(x)
    for i in xrange(1, rounds):
        x = x[1:] + x[0]
        if int(x) not in primes:
            return False
    return True

print sum(circular(p) for p in primes)
