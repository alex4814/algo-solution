#include <stdio.h>

char py[10][5] = {
	"ling",
	"yi",
	"er",
	"san",
	"si",
	"wu",
	"liu",
	"qi",
	"ba",
	"jiu",
};

int main() {
	int n;
	scanf("%d", &n);
	if (n < 0) {
		printf("fu ");
		n = -n;
	} else if (n == 0) {
		printf("ling\n");
		return 0;
	}
	int d[10], m = 0, i;
	while (n > 0) {
		d[m++] = n % 10;
		n /= 10;
	}
	for (i = m - 1; ~i; --i) {
		printf("%s%c", py[ d[i] ], i ? ' ' : '\n');
	}
	return 0;
}
