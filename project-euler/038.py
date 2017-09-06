def concat(n, p):
   s = []
   for m in xrange(1, p+1):
      s.append(str(n * m))
   return ''.join(s)


def pandigital(s):
   if len(s) != 9:
      return False
   digits = {d for d in s}
   return '0' not in digits and len(digits) == 9


p9 = []
for n in xrange(1, 10000):
   for p in xrange(2, 10):
      s = concat(n, p)
      if pandigital(s):
         p9.append(s)
         
print sorted(p9, reverse=True)[0]
