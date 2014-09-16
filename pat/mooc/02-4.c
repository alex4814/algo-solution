#include <stdio.h>

int main() {
	int mask = (1 << 4) - 1;
	int x, i, r = 0, b = 1;
	scanf("%d", &x);
	for (i = 0; i < 4; ++i) {
		r += (x & mask) * b;
		x >>= 4;
		b *= 10;
	}
	printf("%d\n", r);
	return 0;
}
