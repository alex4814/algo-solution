#include <stdio.h>
#define MAXN 1000005

int a[MAXN], b[MAXN];
int na, nb, n;
int s, t, cnt;

main() {
	while (scanf("%d", &n), ~n) {
		a[na++] = n;
	}
	while (scanf("%d", &n), ~n) {
		b[nb++] = n;
	}
	while (s < na && t < nb) {
		if (cnt++) { putchar(' '); }
		if (a[s] <= b[t]) {
			printf("%d", a[s]);
			s++;
		} else {
			printf("%d", b[t]);
			t++;
		}
	}
	while (s < na) { 
		if (cnt++) { putchar(' '); }
		printf("%d", a[s++]);
	}
	while (t < nb) { 
		if (cnt++) { putchar(' '); }
		printf("%d", b[t++]);
	}
	cnt ? printf("\n") : printf("NULL\n");
	return 0;
}
