from itertools import permutations

g = permutations('0123456789')
for i in xrange(1000000):
    p = next(g)
print ''.join(p)
