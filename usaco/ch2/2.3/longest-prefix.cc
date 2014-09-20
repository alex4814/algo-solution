/*
ID: alex4814
LANG: C++
TASK: prefix
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
#define MAXN 200005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int tr[205 << 4][26], n, sz, rt;
int w[205 << 4];
char p[15], line[80];
char s[MAXN];
bool f[MAXN];

// s[u, v]
bool is_primitive(int u, int v) {
	rt = 0;
	for (int i = u; i <= v; ++i) {
		int c = s[i] - 'A';
		if (tr[rt][c] == 0) return false;
		rt = tr[rt][c];
	}
	return w[rt] == 1;
}

#define FILEIO

int main() {
#ifdef FILEIO
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
#endif
	while (scanf("%s", p)) {
		if (p[0] == '.') break;
		sz = strlen(p);
		rt = 0;
		for (int i = 0; i < sz; ++i) {
			int c = p[i] - 'A';
			if (tr[rt][c] == 0) {
				tr[rt][c] = ++n;
			}
			rt = tr[rt][c];
		}
		w[rt] = 1;
	}
	s[0] = '1', s[1] = '\0';
	while (scanf("%s", line) != EOF) {
		strcat(s, line);
	}
	f[0] = true;
	sz = strlen(s + 1);
	//printf("length = %d\n", sz);
	for (int i = 1; i <= sz; ++i) {
		bool ok = false;
		for (int k = 0; k < 10; ++k) {
			if (i - k <= 0) break;
			if (f[i - k - 1] != 1) continue;
			if (is_primitive(i - k, i)) {
				ok = true; break;
			}
		}
		f[i] = ok;
	}
	for (int i = sz; i >= 0; --i) {
		if (f[i] == 1) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}


