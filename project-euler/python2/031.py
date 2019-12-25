coins = [1, 2, 5, 10, 20, 50, 100, 200]

ways = []
for i in xrange(0, 201):
    way = [0] * (len(coins) + 1)
    ways.append(way)

ways[0] = [1] * len(ways[0])
for t in xrange(1, 201):
    for i, c in enumerate(coins):
        n = t / c + 1
        ways[t][i+1] = sum(ways[t-c*j][i] for j in xrange(n))
print ways[200][8]
