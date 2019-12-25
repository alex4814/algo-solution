N = 1000000

chains = [ 
    [169, 363601, 1454],
    [871, 45361],
    [872, 45362],
]

cycles = {
    x: len(chain)
    for chain in chains
    for x in chain
}

factorial = [1]
for n in xrange(1, 10):
    factorial.append(factorial[-1] * n)


def sum_of_factorial(n):
    return sum(factorial[int(d)] for d in str(n))


for n in xrange(N):
    if sum_of_factorial(n) == n:
        cycles[n] = 1


target_length = 60
total = 0
for x in xrange(N):
    y = x
    length = 0
    while True:
        if x in cycles:
            length += cycles[x]
            break
        x = sum_of_factorial(x)
        length += 1
    if length == target_length:
        print y
        total += 1
print total

