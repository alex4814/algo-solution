from fractions import Fraction

N = 1000001
candidates = [Fraction(int(3./7*i), i) for i in xrange(2, N)]
candidates.sort(reverse=True)
for f in candidates:
    if f == Fraction(3, 7):
        continue
    break
print f

