from array import array

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

def identity(x):
    d = [0] * 10
    for c in str(x):
        idx = ord(c) - ord('0')
        d[idx] += 1
    return tuple(d)

def is_permutations(pop):
    counts = [identity(x) for x in pop]
    return len(set(counts)) <= 1

primes = set(primes)

for p in primes:
    if p < 1000:
        continue
    for diff in xrange(2, 4500, 2):
        seq = [p, p + diff, p + diff * 2]
        if not all(x in primes for x in seq):
            continue
        if not is_permutations(seq):
            continue
        cat = ''.join(str(x) for x in seq)
        print '{} -> {}'.format(seq, cat)
