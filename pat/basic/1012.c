#include <stdio.h>
#define max(a, b) (a)>(b)?(a):(b)
#define MAXN 1000

int a[MAXN], ret[5], cnt[5];

int main() {
	int neg = 1, i, n;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] % 5 == 0 && !(a[i] & 1)) {
			ret[0] += a[i];
			cnt[0] += 1;
		} if (a[i] % 5 == 1) {
			ret[1] += neg * a[i];
			cnt[1] += 1;
			neg = -neg;
		} if (a[i] % 5 == 2) {
			ret[2] += 1;
			cnt[2] += 1;
		} if (a[i] % 5 == 3) {
			ret[3] += a[i];
			cnt[3] += 1;
		} if (a[i] % 5 == 4) {
			ret[4] = max(ret[4], a[i]);
			cnt[4] += 1;
		}
	}
	cnt[0] ? printf("%d", ret[0]) : printf("N");
	cnt[1] ? printf(" %d", ret[1]) : printf(" N");
	cnt[2] ? printf(" %d", cnt[2]) : printf(" N");
	cnt[3] ? printf(" %.1f", ret[3] * 1.0 / cnt[3]) : printf(" N");
	cnt[4] ? printf(" %d\n", ret[4]) : printf(" N\n");
	return 0;
}

