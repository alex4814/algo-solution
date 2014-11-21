#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define INF 0x3f3f3f3f
#define MAXN 105
#define MAXL 260

typedef pair<int, int> pii;
typedef long long ll;

char s[MAXN][MAXL];
char t[MAXL];

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	int m = INF;
	for (int i = 0; i < n; ++i) {
		fgets(t, MAXL, stdin);
		int len = strlen(t);
		for (int j = 0; j < len - 1; ++j) {
			s[i][j] = t[len - 2 - j];
		}
		s[i][len - 1] = '\0';
		m = min(m, len - 1);
	}
	int r = 0;
	for (int i = 0; i < m; ++i) {
		bool same = true;
		for (int j = 1; j < n; ++j) {
			if (s[j][i] != s[j - 1][i]) {
				same = false;
				break;
			}
		}
		if (!same) break;
		r += 1;
	}
	if (r) {
		while (r >= 0) {
			putchar(s[0][--r]);
		}
		putchar('\n');
	} else {
		puts("nai");
	}
	return 0;
}


