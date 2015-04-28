#include <stdio.h>
#define MAXN 100000

typedef long long ll;
ll n;
int i, j, e;

int f[MAXN], p[MAXN], pn;
int ex[MAXN];

void init() {
	for (i = 2; i < MAXN; ++i) {
		if (!f[i]) p[pn++] = i;
		for (j = 0; j < pn && p[j] * i < MAXN; ++j) {
			f[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

void factoring() {
	for (i = 0; i < pn; ++i) {
		e = 0;
		while (n % p[i] == 0) {
			n /= p[i];
			e += 1;
		}
		ex[i] = e;
		if (n == 1) break;
	}
}

int all_zero() {
	for (i = 0; i < pn; ++i) if (ex[i]) return 0;
	return 1;
}

void print() {
	if (all_zero()) {
		printf("%lld\n", n);
		return;
	}
	for (i = MAXN - 1; ~i; --i) if (ex[j = i]) break;
	for (i = 0; i < j; ++i) if (ex[i]) {
		printf("%d", p[i]);
		ex[i] > 1 ? printf("^%d", ex[i]) : 0;
		printf("*");
	}
	printf("%d", p[j]);
	ex[j] > 1 ? printf("^%d\n", ex[j]) : printf("\n");
}

main() {
	init();
	scanf("%lld", &n);
	printf("%lld=", n);
	factoring();
	print();
	return 0;
}
