n = int(raw_input())
b = (n / 100) % 10
s = (n / 10) % 10
g = n % 10

ret = ""
for i in range(b):
	ret += 'B'
for i in range(s):
	ret += 'S'
for i in range(g):
	ret += str(i + 1)
print ret
