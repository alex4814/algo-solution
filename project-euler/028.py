def south_east_diagona(n):
    x = 3
    step = 2
    yield x, step
    for i in xrange(1, n/2):
        x = x + i * 2 * 3 + (i + 1) * 2
        yield x, (i + 1) * 2

total = 1
for x, step in south_east_diagona(1001):
    total += (x + x + step * 3) * 2
print total
