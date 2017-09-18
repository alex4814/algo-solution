def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


class Fraction(object):
    """Assume both numerator and denominator are all positive.
    """
    def __init__(self, n, d):
        g = gcd(n, d)
        self.n = n / g
        self.d = d / g
    
    def reverse(self):
        self.n, self.d = self.d, self.n

    def __add__(self, other):
        n = self.n * other.d + self.d * other.n
        d = self.d * other.d
        return Fraction(n, d)

num = Fraction(0, 1)
exp = Fraction(1, 2)
cnt = 0
for i in xrange(1000):
    num = Fraction(1, 1) + exp
    cnt += len(str(num.n)) > len(str(num.d))
    exp += Fraction(2, 1)
    exp.reverse()
print cnt
