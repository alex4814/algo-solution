from array import array
from operator import mul

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

def number_of_divisors(x):
    exps = []
    for p in primes:
        exp = 0
        while x % p == 0:
            exp += 1
            x /= p
        if exp > 0:
            exps.append(exp)
        if x == 1:
            break
    return reduce(mul, [e+1 for e in exps], 1)

n = 1
i = 2

while True:
    if number_of_divisors(n) > 500:
        break
    n += i
    i += 1

print n
