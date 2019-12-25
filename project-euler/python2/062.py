length = 1
n = 1
count = {}

found = False
while not found:
    x = n**3
    if len(str(x)) == length:
        p = tuple(str(x).count(str(d)) for d in xrange(10))
        count.setdefault(p, []).append(x)
        n += 1
        continue
    for value in count.itervalues():
        if len(value) == 5:
            found = True
            print sorted(value)
    length += 1
    count = {}

