N = 101

# f(i, j) stores how many ways to 
# write i starting with j (the maximum)
# i >= j
f = []
for i in xrange(N):
    row = [0] * N
    f.append(row)

for i in xrange(N):
    f[i][i] = 1
for i in xrange(1, N):
    for j in xrange(1, i):
        d = i - j
        for k in xrange(j):
            f[i][j] += f[d][k+1]

n = 100
ways = 0
for j in xrange(n):
    ways += f[n][j]
print ways

