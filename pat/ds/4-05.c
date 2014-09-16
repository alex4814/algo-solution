#include <stdio.h>

#define MAXN 100
int n, m, cnt;

struct Person {
	char name[20];
	Person *p, *ch[];
};

main() {
	int i;

	scanf("%d%d", &n, &m);
	build(1);
	return 0;
}
