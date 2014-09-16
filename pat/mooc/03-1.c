#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf((n - 1) % 5 < 3 ? "Fishing" : "Drying");
	printf(" in day %d\n", n);
	return 0;
}
