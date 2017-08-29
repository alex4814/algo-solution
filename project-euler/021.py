# To quickly find the sum of proper divisors
# See https://math.stackexchange.com/questions/22721/is-there-a-formula-to-calculate-the-sum-of-all-proper-divisors-of-a-number

from array import array
from operator import mul

MAX = 10001
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

sums = [sum_of_divisors(x) - x for x in range(0, MAX)]
amicables = [i for i, total in enumerate(sums) if total < MAX and total != i and sums[total] == i]
print sum(amicables)
