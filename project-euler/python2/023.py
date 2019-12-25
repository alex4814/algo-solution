from array import array
from operator import mul

MAX = 28123 + 1
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

def sum_of_divisors(x):
    if x == 0 or x == 1:
        return 0
    factors = []
    for p in primes:
        exp = 0
        while x % p == 0:
            x /= p
            exp += 1
        if exp > 0:
            factors.append((p, exp))
        if x == 1:
            break
    return reduce(mul, [(1 - p**(exp+1)) / (1 - p) for p, exp in factors])

is_abundant = [sum_of_divisors(x) > x + x for x in xrange(MAX)]
abundants = [n for n, b in enumerate(is_abundant) if b]

is_composite = [False] * MAX
for a in abundants:
    for b in abundants:
        if a + b >= MAX:
            break
        is_composite[a + b] = True

total = sum(n for n, b in enumerate(is_composite) if not b)
print total
