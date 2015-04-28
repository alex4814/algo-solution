#include <cstdio>
#include <cstring>
using namespace std;

#define _N 1005

int t, n, p, q, letter;
char s[_N];

int main() {
	scanf("%d", &t); getchar();
	while (t--) {
		fgets(s, _N, stdin);

		letter = 0;
		n = strlen(s);
		p = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == ' ' && letter) {
				letter = 0;
				for (q = i - 1; q >= p; --q) {
					putchar(s[q]);
				}
				putchar(' ');
				p = i + 1;
			} else if (s[i] == ' ') {
				putchar(' ');
				p = i + 1;
			} else if (i == n - 1) {
				for (q = i - 1; q >= p; --q) {
					putchar(s[q]);
				}
				putchar('\n');
			} else {
				letter = 1;
			}
		}
	}
	return 0;
}
