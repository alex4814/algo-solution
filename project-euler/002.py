def fibonacci(n):
    a, b = 1, 2
    while a <= n:
        yield a
        a, b = b, a + b

target = 4000000
print sum(n for n in fibonacci(target) if n % 2 == 0)
