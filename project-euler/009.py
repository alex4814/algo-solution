for a in xrange(0, 1000):
    for b in xrange(a+1, 1000):
        c = 1000 - a - b
        if c <= b:
            break
        if a * a + b * b == c * c:
            print a * b * c
