from array import array
from itertools import combinations
import math

MAX = 10000
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

primes_set = set(primes)

def is_prime(y):
    if y < MAX:
        return y in primes_set
    if y % 2 == 0:
        return False
    u = int(math.sqrt(float(y)))
    for p in primes:
        if p > u:
            break
        if y % p == 0:
            return False
    return True

def match(*args):
    for a, b in combinations(args, 2):
        n = str(a) + str(b)
        m = str(b) + str(a)
        if not is_prime(int(n)) or not is_prime(int(m)):
            return False
    return True

candidates = {}
for p in primes:
    lst = candidates.setdefault(p, set())
    for q in primes:
        if p == q:
            continue
        n = str(p) + str(q)
        m = str(q) + str(p)
        if is_prime(int(n)) and is_prime(int(m)):
            lst.add(q)

pairs = []
for a in primes:
    for b in candidates[a]:
        if b < a:
            continue
        common = candidates[a] & candidates[b]
        if len(common) < 3:
            continue
        for cde in combinations(common, 3):
            if match(*cde):
                pairs.append((a, b) + cde)
print pairs
if pairs:
    print 'Result:', max(sum(p) for p in pairs)
