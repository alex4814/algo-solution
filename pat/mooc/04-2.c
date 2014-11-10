#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= r; ++c) {
			printf("%d*%d=%-4d", c, r, c * r);
		}
		putchar('\n');
	}
	return 0;
}
