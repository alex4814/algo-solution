#include <stdio.h>

int cnt, a;
char in[10];

void dfs(int n, int c, int p) {
	if (p == 3) {
		printf("%d", n);
		putchar(++cnt % 6 == 0 ? '\n' : ' ');
		return;
	}
	in[c] = 1;
	for (int i = 0; i < 4; ++i) {
		if (in[a + i]) continue;
		dfs(n * 10 + c, a + i, p + 1);
	}
	in[c] = 0;
}

int main() {
	scanf("%d", &a);
	for (int i = 0; i < 4; ++i) {
		dfs(0, i + a, 0);
	}
	return 0;
}
