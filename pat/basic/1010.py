line = raw_input().split()
n = len(line) / 2
f = 0
for i in range(n):
	a0 = int(line[2 * i])
	e0 = int(line[2 * i + 1])
	if e0 != 0:
		print a0 * e0, e0 - 1,
		f = 1
	if f == 0:
		print 0, 0
