import math

n = 600851475143
the_factor = 1

if n % 2 == 0:
    the_factor = 2
    while n % 2 == 0:
        n /= 2

factor = 3
max_factor = int(math.sqrt(n))
while factor <= max_factor:
    if n % factor == 0:
        the_factor = factor
        while n % factor == 0:
            n /= factor
        max_factor = int(math.sqrt(n))
    factor += 2

if n != 1:
    the_factor = n
print the_factor
