from array import array

MAX = 655000
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

def prime_factors(x):
    cnt = 0
    i = 0
    while x > 1 and i < len(primes):
        if x % primes[i] == 0:
            cnt += 1  
            while x % primes[i] == 0:
                x /= primes[i]
        i += 1
    if x > 1:
        print 'prime factor inadequate for', x
    return cnt

n = 2*3*5*7
while True:
    m = [n+i for i in range(4)]
    if all(prime_factors(x) >= 4 for x in m):
        break
    n += 1
print m
