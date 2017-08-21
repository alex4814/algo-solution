def palindromic(n):
    s = str(n)
    return s == s[::-1]

print max(x * y for x in xrange(100, 1000)
                for y in xrange(100, 1000)
                if palindromic(x * y))
