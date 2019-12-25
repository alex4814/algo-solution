c = []
for i in xrange(101):
    row = [0] * 101
    c.append(row)

c[0][0] = 1
c[1][1] = 1
for n in xrange(1, 101):
    c[n][0] = 1
    for i in xrange(1, n+1):
        c[n][i] = c[n-1][i-1] + c[n-1][i]

greater = [(n, i, c[n][i]) for n in xrange(1, 101)
                           for i in xrange(0, n+1)
                           if c[n][i] > 1000000]
print greater
print 'length', len(greater)
