primes = [2, 3, 5, 7, 11, 13, 17, 19]
powers = [0] * len(primes)

for n in xrange(1, 21):
    for i, p in enumerate(primes):
        cnt = 0
        while n % primes[i] == 0:
            cnt += 1
            n /= primes[i]
        powers[i] = max(powers[i], cnt)

n = 1
for b, p in zip(primes, powers):
    n *= b ** p
print n
