#include <stdio.h>
#define MAXN 200005

int d[MAXN], n, a;

main() {
	int i, s;

	scanf("%d%d", &a, &n);
	if (n == 0) {
		printf("0\n");
	} else {
		for (i = 0; i < n; ++i) {
			d[i] += (n - i) * a;
			d[i] > 9 ? d[i + 1] += d[i] / 10, d[i] %= 10 : 0;
		}
		for (; i < MAXN; ++i) {
			d[i] > 9 ? d[i + 1] += d[i] / 10, d[i] %= 10 : 0;
		}

		s = 0;
		for (i = MAXN - 1; ~i; --i) {
			s ? printf("%d", d[i]) : 0;
			!s && d[i] ? s = 1, printf("%d", d[i]) : 0;
		}
		printf("\n");
	}
	return 0;
}
