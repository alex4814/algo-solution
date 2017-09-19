def is_prime(y):
    import math
    if y % 2 == 0:
        return False
    u = int(math.sqrt(float(y)))
    for p in xrange(3, u+1, 2):
        if y % p == 0:
            return False
    return True


step = 2
start = 1

n_primes = 0
n_total = 1

while True:
    for i in range(4):
        start += step
        if is_prime(start):
            n_primes += 1
    n_total += 4
    if float(n_primes) / n_total < 0.1:
        break
    step += 2
print step + 1
