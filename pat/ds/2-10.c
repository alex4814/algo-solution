#include <stdio.h>

main() {
	int d, p;
	scanf("%d%d", &d, &p);
	printf("%d\n", p / 2 > 1 ? d - p / 2 - 1 : d - p / 2);
	return 0;
}
