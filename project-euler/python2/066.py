# Pell's equation
# Link: https://en.wikipedia.org/wiki/Pell%27s_equation

# Using fundamental solution via continued fractions

p64 = __import__('064')
p65 = __import__('065')


def partials(n, cycle):
    groups = n / len(cycle)
    remains = n % len(cycle)
    for i in xrange(remains):
        yield cycle[remains-1-i]
    for i in xrange(groups):
        for j in xrange(len(cycle)):
            yield cycle[-1-j]


def representation(x, a0):
    terms = []
    next_ = (a0, x, a0, 1)
    while True:
        next_ = p64.expand(*next_)
        if next_ in terms:
            break
        terms.append(next_)
    terms = [t[0] for t in terms]
    return a0, terms


def approximation(ith, a0, terms):
    if ith == 0:
        return a0, 1
    s = p65.Fraction(0, 1)
    for p in partials(ith, terms):
        s = (s + p65.Fraction(p, 1)).reciprocal()
    s += p65.Fraction(a0, 1)
    return s.n, s.d


solutions = {}
for d, a0 in p64.non_square(1001):
    a0, terms = representation(d, a0)
    n = 0
    while True:
        x, y = approximation(n, a0, terms)
        if x**2 - d * y**2 == 1:
            print '{x}^2 - {d}*{y}^2 = 1'.format(x=x, d=d, y=y)
            solutions[x] = (d, y)
            break
        n += 1
xmax = max(solutions.keys())
print solutions[xmax]

