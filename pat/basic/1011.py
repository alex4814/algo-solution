t = int(raw_input())
for i in range(t):
	s = raw_input().split()
	a = int(s[0])
	b = int(s[1])
	c = int(s[2])
	if a + b > c:
		print "Case #%d: %s" % (i + 1, "true")
	else:
		print "Case #%d: %s" % (i + 1, "false")
