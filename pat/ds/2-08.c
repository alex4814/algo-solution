#include <stdio.h>
#define EPS 1e-8

inline int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

int i, found;
int a[4];
int op[3];	// 0 for +, 1 for -, 2 for *, 3 for /

int as[4], os[3], ap, op;
int work() {
	op = -1;
	as[0] = a[0];
	
}

main() {
	for (i = 0; i < 4; ++i) {
		scanf("%d", &a[i]);
	}
	for (op[0] = 0; op[0] < 4; ++op[0]) {
		for (op[1] = 0; op[1] < 4; ++op[1]) {
			for (op[2] = 0; op[2] < 4; ++op[2]) {
				if (work()) {
					found = 1; break;
				}
			}
		}
	}
	found ? 0 : printf("-1\n");
	return 0;
}
