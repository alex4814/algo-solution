import sys
words = sys.stdin.readline().split()
words = words[::-1]
for i in range(len(words)):
	print words[i],
