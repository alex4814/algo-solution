def first_fibonacci_of_length(n):
    a, b = 1, 1
    n = 1
    while True:
        if len(str(a)) == 1000:
            return n
        a, b = b, a + b
        n += 1

print first_fibonacci_of_length(1000)
