import sys

line = sys.stdin.readline().split()
n = int(line[0])
m = int(line[1])
m = m % n
arr = sys.stdin.readline().split()
for i in range(n - m, n):
	print arr[i],
for i in range(n - m):
	print arr[i],

