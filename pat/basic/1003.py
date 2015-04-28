def acc(s):
	cnt = [0] * 26
	for i in range(len(s)):
		if str.isupper(s[i]):
			cnt[ord(s[i]) - ord('A')] += 1
			if s[i] == 'P':
				pix = i
			elif s[i] == 'T':
				tix = i
		else:
			return False
	for i in range(26):
		if cnt[i] > 0 and i != 0 and i != 15 and i != 19:
			return False
	if cnt[0] < 1 or cnt[15] != 1 or cnt[19] != 1:
		return False
	return pix * (tix - pix - 1) == len(s) - tix - 1

n = int(raw_input())
while n > 0:
	n -= 1;
	s = raw_input()
	if (acc(s)):
		print "YES"
	else:
		print "NO"
	
