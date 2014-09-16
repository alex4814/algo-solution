n = int(raw_input())
a = raw_input().split()
avg = 0
for i in range(n):
	avg += float(a[i])
avg /= n
ret = 0
for i in range(n):
	ret = ret + (float(a[i]) - avg) ** 2
print "%.5f" % ((ret / n) ** 0.5)
