def d_(n):
    """Generate the n-th digit of the irrational decimal fraction x, by concatenating 
    the positive integers: 0.123456789101112131415161718192021...
    """
    x = 0
    cnt = 0
    while True:
        for d in str(x):
            yield int(d)
            if cnt == n:
                return
            cnt += 1
        x += 1

targets = {1, 10, 100, 1000, 10000, 100000, 1000000}
product = 1
for i, d in enumerate(d_(1000000)):
    if i in targets:
        product *= d
print product
