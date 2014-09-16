#include <stdio.h>

int main() {
	int i;
	char s[4];
	scanf("%s", s);
	for (i = 2; i >= 0; --i) {
		if (s[i] != '0') putchar(s[i]);
	}
	putchar('\n');
	return 0;
}
