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

def truncatable(x):
    if x not in primes:
        return False
    x = str(x)
    for i in xrange(1, len(x)):
        if int(x[i:]) not in primes:
            return False
        if int(x[:-i]) not in primes:
            return False
    return True
    
both = []
for n in xrange(22, MAX):
    if truncatable(n):
        both.append(n)
print both
print 'length {}, and sum {}'.format(len(both), sum(both))
