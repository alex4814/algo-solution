#include <stdio.h>

int gcd(int a, int b) {
	while (b ^= a ^= b ^= a %= b);
	return a;
}

char e[100];

int main() {
	int nr, dr;
	scanf("%s", e);
	sscanf(e, "%d/%d", &nr, &dr);
	int d = gcd(nr, dr);
	printf("%d/%d\n", nr / d, dr / d);
	return 0;
}
