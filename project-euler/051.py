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

primes_set = set(primes)

def sublists(thelist, k):
    n = len(thelist)
    if k == 0:
        yield list(), 0
    elif k == n:
        yield list(thelist), n
    elif k < n:
        for sublist, idx in sublists(thelist[:-1], k - 1):
            for i, item in enumerate(thelist[idx:], idx):
                yield sublist + [item], i + 1

def replace(p, d, l):
    families = []
    if p.count(d) < l:
        return [[int(p)]]
    indices = [i for i, x in enumerate(p) if x == d]
    for sub, _ in sublists(indices, l):
        digits = list(p)
        family = []
        base = int(d)
        for a in xrange(10):
            if base + a > 9:
                break
            for idx in sub:
                digits[idx] = str(base+a)
            rp = int(''.join(digits))
            if rp in primes_set:
                family.append(rp)
        families.append(family)
    return families

def found(p):
    sp = str(p)

    # The smallest prime in an eight prime value family
    # should not exceed 2 as the replacing digit 
    m = max([sp.count(str(i)) for i in range(3)])
    for i in range(3):
        for l in range(1, m+1):
            families = replace(sp, str(i), l)
            for family in families:
                if len(family) == 8:
                    print family
                    return True
    return False
    
for p in primes:
    if found(p):
        break
