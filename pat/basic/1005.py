import sys

inlist = [0] * 10005
covered = [0] * 10005

def cover(x):
	while x > 1:
		if x % 2 == 0:
			x /= 2
		else:
			x = (3 * x + 1) / 2
		covered[x] = 1

n = int(raw_input())
num = sys.stdin.readline().split() 
for i in range(n):
	inlist[int(num[i])] = 1
	cover(int(num[i]))

ret = []
for i in range(101):
	if inlist[i] == 1 and covered[i] == 0:
		ret.append(i)
ret = ret[::-1]
for i in range(len(ret)):
	print ret[i],
