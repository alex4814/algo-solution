
n = int(raw_input())
prime = []
np = [0] * (n + 1)
for i in range(2, n + 1):
	if np[i] == 0:
		prime.append(i)
	for j in range(0, len(prime)):
		k = i * prime[j];
		if k > n:
			break
		np[k] = 1
		if i % prime[j] == 0:
			break

cnt = 0
for i in range(1, len(prime)):
	if prime[i] - prime[i - 1] == 2:
		cnt += 1
print cnt
