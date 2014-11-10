#include <stdio.h>

int main() {
	int a, n;
	scanf("%d %d", &a, &n);
	int i, d = a, sum = d;
	for (i = 1; i < n; ++i) {
		a = a * 10 + d;
		sum += a;
	}
	printf("%d\n", sum);
	return 0;
}
