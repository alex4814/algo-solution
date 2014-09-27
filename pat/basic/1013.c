#include <stdio.h>
#define MAXN 1000005

int p[MAXN], pn, f[MAXN];
int n, m, i, j, c = 0;


void init() {
	for (i = 2; i < MAXN; ++i) {
		if (!f[i]) p[pn++] = i;
		for (j = 0; j < pn && p[j] * i < MAXN; ++j) {
			f[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

main() {
	init();
	scanf("%d%d", &m, &n);
	if (m < 1) m = 1;
	for (i = m - 1; i < n; ++i) {
		if (c++) putchar(' ');
		printf("%d", p[i]);
		if (c == 10) {
			c = 0;
			putchar('\n');
		}
	}
	putchar('\n');
	return 0;
}
