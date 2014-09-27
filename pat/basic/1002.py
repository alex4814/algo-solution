n = raw_input()
py = ["ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"]
dsum = 0
for i in range(len(n)):
	dsum += int(n[i])
d = '%d' % dsum
for i in range(len(d)):
	print py[int(d[i])],

