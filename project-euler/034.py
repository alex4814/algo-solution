f = [1]
for i in xrange(1, 10):
    f.append(f[i-1] * i)

def curious(n):
    m = n
    total = 0
    while m > 0:
        total += f[m % 10]
        m /= 10
    return total == n

# Assume the curious number has 7 digits,
# however 9! = 362880 which has 6 digits.
# To be `curious`, 8! = 40320 also considered,
# we try 9999999 which does not equal 9! * 7,
# and six 9s and one 8, and five 9s and two 8s...
# Finally, we come to two 9s and five 8s, where
# 9! * 2 + 8! * 5 = 927360, has only 6 digits in total,
# contrary to 7 digits we assume at the beginning.
# Thus, we conclude that curious number has at most 6 digits.
max_digits = 6

total = 0
for x in xrange(10, 10**max_digits):
    if curious(x):
        total += x
print total
