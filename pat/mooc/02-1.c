#include <stdio.h>

int main() {
	int x, foot, inch;
	scanf("%d", &x);
	foot = x / 30.48;
	inch = 12 * (x / 30.48 - foot);
	printf("%d %d\n", foot, inch);
}
