/*
ID: alex4814
LANG: C++
TASK: lamps
*/

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
#define MAXN 105
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n, c;
char s[16][MAXN];
int m[16] = {
   0, 1, 1, 2, 1, 2, 2, 3,
   1, 2, 2, 3, 2, 3, 3, 4,
};
int b[4] = { 0, 0, 1, 0 };
int t[4] = { 1, 2, 2, 3 };
int on[MAXN], n1;
int off[MAXN], n2;
int x;
vector<char *> r;

bool cmp(char *a, char *b) {
	return strcmp(a, b) < 0;
}

int check() {
	for (int k = 0; k < 16; ++k) {
		bool ok = true;
		for (int i = 0; i < n1; ++i) {
			if (s[k][ on[i] - 1 ] != '1') {
				ok = false; break;
			}
		}
		if (!ok) continue;
		for (int i = 0; i < n2; ++i) {
			if (s[k][ off[i] - 1 ] != '0') {
				ok = false; break;
			}
		}
		if (!ok || c < m[k] || (c - m[k]) & 1) continue;
		r.push_back(s[k]);
	}
	return r.size() > 0;
}

int main() {
#ifdef FILEIO
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
#endif

	scanf("%d %d", &n, &c);
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < n; ++j) {
			s[i][j] = '1';
		}
		s[i][n] = '\0';
		//printf("%x, %s\n", i, s[i]);
		for (int k = 0; k < 4; ++k) {
			if (i & (1 << k)) {
				for (int j = b[k]; j < n; j += t[k]) {
					s[i][j] = ((s[i][j] - '0') ^ 1) + '0';
				}
			}
		}
		//printf("%x, %s\n", i, s[i]);
	}
	while (scanf("%d", &x) && ~x) {
		on[n1++] = x;
	}
	while (scanf("%d", &x) && ~x) {
		off[n2++] = x;
	}
	if (check()) {
		sort(r.begin(), r.end(), cmp);
		for (int i = 0; i < (int)r.size(); ++i) {
			printf("%s\n", r[i]);
		}
	} else {
		printf("IMPOSSIBLE\n");
	}

	return 0;
}


