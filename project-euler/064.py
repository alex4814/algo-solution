import math


def non_square(n):
    x = 1
    y = 1
    lo, hi = 1**2, 2**2
    while y < n:
        if y == hi:
            x += 1
            lo = x**2
            hi = (x+1)**2
            continue
        if y > lo:
            yield y, x
        y += 1


def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a


def expand(*args):
    ai, fsr, fm, fd = args
    d = fsr - fm**2
    g = gcd(d, fd)
    d /= g
    fd /= g
    assert fd == 1

    ai = 1
    sqrt = math.sqrt(fsr)
    while True:
        diff = d * ai - fm
        if sqrt - diff <= d:
            fm = diff
            fd = d
            break
        ai += 1
    return ai, fsr, fm, fd


odd = 0
for x, a0 in non_square(10001):
    next_ = (a0, x, a0, 1)
    terms = []
    while True:
        next_ = expand(*next_)
        if next_ in terms:
            break
        terms.append(next_)
    ai = [t[0] for t in terms]
    print 'sqrt({}) = [{};({})]'.format(x, a0, ai)
    odd += (len(terms) & 1 > 0)
print odd

