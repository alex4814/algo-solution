#include <stdio.h>
#define MAXN 1000005

int a[MAXN];
int k, n, d;

main() {
	scanf("%d", &k);
	while (scanf("%d", &d), d >= 0) {
		a[n++] = d;
	}
	k > n ? printf("NULL\n") : printf("%d\n", a[n - k]);
	return 0;
}
