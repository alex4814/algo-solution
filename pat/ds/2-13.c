#include <stdio.h>
#define MAXN 100005

int a[MAXN], b[MAXN];
int n, i, s, t, x, cnt;

main() {
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	while (s < n && t < n) {
		if (a[s] <= b[t]) {
			x = a[s++];
		} else {
			x = b[t++];
		}
		if (++cnt == n) {
			printf("%d\n", x);
			break;
		}
	}
	return 0;
}
