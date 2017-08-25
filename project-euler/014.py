n = 1000000
chains = [0] * n

for x in xrange(1, n):
    cnt = 0
    target = x
    while x != 1:
        if x < n and chains[x]:
            break
        if x % 2 == 0:
            x /= 2
        else:
            x = 3 * x + 1
        cnt += 1
    chains[target] = chains[x] + cnt

length = max(chains)
print chains.index(length)
