def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

def is_lychrel(n):
    round = 0
    while round < 50:
        n = n + int(str(n)[::-1])
        if is_palindrome(n):
            return False
        round += 1
    return True

lychrels = [is_lychrel(n) for n in xrange(10000)]
print sum(lychrels)

