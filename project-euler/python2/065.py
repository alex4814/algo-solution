class Fraction(object):
    def __init__(self, n, d):
        assert d > 0
        assert n >= 0
        g = self.gcd(n, d)
        self.n = n / g
        self.d = d / g

    @staticmethod
    def gcd(a, b):
        while b > 0:
            a, b = b, a % b
        return a

    def __str__(self):
        return '{}/{}'.format(self.n, self.d)

    def __add__(self, other):
        d = self.d * other.d
        n = self.n * other.d + self.d * other.n
        return Fraction(n, d)

    def reciprocal(self):
        return Fraction(self.d, self.n)


def partials(n):
    groups = n / 3
    remains = n % 3
    g = (1, 2*(groups+1), 1)
    if remains == 2:
        yield g[1]
        yield g[2]
    elif remains == 1:
        yield g[2]
    else:
        for x in xrange(groups, 0, -1):
            yield 1
            yield 2 * x
            yield 1


def main():
    s = Fraction(0, 1)
    for p in partials(99):
        s = (s + Fraction(p, 1)).reciprocal()
    s += Fraction(2, 1)
    print sum(map(int, str(s.n)))


if __name__ == '__main__':
    main()

