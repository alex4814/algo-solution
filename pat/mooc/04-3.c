#include <stdio.h>
#include <math.h>

int is_prime(int x) {
	int n = sqrt(x), i;
	for (i = 2; i <= n; ++i) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int main() {
	int m, n, x;
	scanf("%d %d", &m, &n);
	int cnt = 0, sum = 0;
	for (x = m; x <= n; ++x) {
		if (x != 1 && is_prime(x)) {
			cnt += 1;
			sum += x;
		}
	}
	printf("%d %d\n", cnt, sum);
	return 0;
}
