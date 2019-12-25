n = 1
for i in xrange(1, 101):
    n *= i
print sum(int(d) for d in str(n))
