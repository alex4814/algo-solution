#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b) puts("C");
	if (b == c) puts("A");
	if (c == a) puts("B");
	return 0;
}
