#include <stdio.h>

int p(int n, int e) {
	int r = 1;
	for (int i = 0; i < e; ++i) {
		r *= n;
	}
	return r;
}

int is_sxhs(int x, int n) {
	int y = x;
	int sum = 0;
	while (x > 0) {
		sum += p(x % 10, n);
		x /= 10;
	}
	return sum == y;
}

int main() {
	int n, upper;
	scanf("%d", &n);
	upper = p(10, n);
	for (int i = p(10, n - 1); i < upper; ++i) {
		if (is_sxhs(i, n)) {
			printf("%d\n", i);
		}
	}
	return 0;
}
