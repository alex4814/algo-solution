#include <stdio.h> 
#define MAXN 1000

int left[MAXN];

main() {
	int i, j, n, s;

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		left[i] = 100;
	}
	for (i = 0; i < n; ++i) {
		scanf("%d", &s);
		for (j = 0; j < n; ++j) {
			if (s <= left[j]) {
				left[j] -= s;
				break;
			}
		}
		printf("%d %d\n", s, j + 1);
	}

	int cnt = 0;
	for (i = 0; i < n; ++i) {
		left[i] != 100 ? ++cnt : 0;
	}
	printf("%d\n", cnt);
	return 0;
}
