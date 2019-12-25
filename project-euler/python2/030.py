numbers = []

# 9**5 * 6 == 254294
for x in xrange(10, 354294):
    sum_of_power = sum(int(c)**5 for c in str(x))
    if sum_of_power == x:
        numbers.append(x)
print sum(numbers)

