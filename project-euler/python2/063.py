numbers = set()
e = 1
stop = False
while not stop:
    stop = True
    for b in xrange(1, 10):
        x = str(b**e)
        if len(x) == e:
            numbers.add(x)
        if len(x) >= e:
            stop = False
    e += 1
print len(numbers)
