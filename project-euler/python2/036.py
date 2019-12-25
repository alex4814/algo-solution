def palindromic(s):
    return s == s[::-1]

n = 0
for i in xrange(1000000):
    if palindromic(str(i)) and palindromic(bin(i)[2:]):
        print 'palindromic', i
        n += i
print n
