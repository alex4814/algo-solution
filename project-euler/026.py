def length_of_recurring_cycle(d):
    digits = {}
    n = 1
    pos = 1
    while n % d:
        n *= 10
        p = n / d
        q = n % d
        last = digits.setdefault((p, q), pos)
        if last != pos:
            return pos - last
        n = q
        pos += 1
    return 0

cycles = [length_of_recurring_cycle(d) for d in xrange(2, 1000)]
longest = max(cycles)
print [n + 2 for n, l in enumerate(cycles) if l == longest]
