with open('p067_triangle.txt', 'r') as f:
    t = '\n'.join(f.readlines())

# Build the matrix
triangles = []
for line in t.splitlines():
    if not line.strip():
        continue
    row = line.split()
    row = [int(n) for n in row]
    triangles.append(row)

# Find the max
n = len(triangles) + 1

f = []
for i in xrange(n):
    row = [0] * n
    f.append(row)

for i in xrange(1, n):
    for j in xrange(1, i+1):
        f[i][j] = max(f[i-1][j-1], f[i-1][j]) + triangles[i-1][j-1]
print max(f[n-1][j] for j in xrange(1, n))

