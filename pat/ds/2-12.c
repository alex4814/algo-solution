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
		if (a[s] == b[t]) {
			if (cnt++) { putchar(' '); }
			printf("%d", a[s]);
			s++, t++;
		} else if (a[s] < b[t]) {
			s++;
		} else {
			t++;
		}
	}
	cnt ? printf("\n") : printf("NULL\n");
	return 0;
}
