#include <stdio.h>

char s[85];
char w[85][85];

int main() {
	int i, k = 0;
	while (scanf("%s", s) != EOF) {
		char *dst = w[k], *src = s;
		while (*dst++ = *src++);
		++k;
	}
	for (i = k - 1; i >= 0; --i) {
		printf("%s%c", w[i], i == 0 ? '\n' : ' ');
	}
	return 0;
}


