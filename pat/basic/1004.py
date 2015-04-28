import sys

name = []
sid = []
max_score = -1 
min_score = 101

n = int(raw_input())
for i in range(n):
	line = sys.stdin.readline().split()
	name.append(line[0])
	sid.append(line[1])
	score = int(line[2])
	if score > max_score:
		max_i = i
		max_score = score
	if score < min_score:
		min_i = i
		min_score = score
print name[max_i], sid[max_i]
print name[min_i], sid[min_i]
