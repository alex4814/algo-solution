def digital_sum(x):
   return sum(int(c) for c in x)

ab = [str(a**b) for a in xrange(100) for b in xrange(100)]
print max(digital_sum(x) for x in ab)

