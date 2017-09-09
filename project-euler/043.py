from itertools import permutations

primes = [0, 2, 3, 5, 7, 11, 13, 17]
g = permutations('0123456789')

def divisible(x):
    for i in xrange(1, 8):
        y = int(x[i:i+3])
        if y % primes[i] != 0:
            return False
    return True

pandigitals = []
for p in g:
    num = ''.join(p)
    if divisible(num):
        pandigitals.append(num)
print pandigitals
print sum(int(p) for p in pandigitals)
