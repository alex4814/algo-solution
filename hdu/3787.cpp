#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAXN 25

char a[MAXN], b[MAXN];
char c[MAXN];

int integer(char *s) {
	int len = strlen(s), n = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == ',') continue;
		c[n++] = s[i];
	}
	c[n] = '\0';
	return atoi(c);
}

int main() {
	while (scanf("%s%s", a, b) == 2) {
		printf("%d\n", integer(a) + integer(b));
	}
	return 0;
}
