n = 20
m = n + 2
routes = [[0] * m] * m

routes[1][1] = 1
for i in xrange(1, m):
    for j in xrange(1, m):
        if i == 1 and j == 1:
            continue
        routes[i][j] = routes[i-1][j] + routes[i][j-1]
print routes[m-1][m-1]