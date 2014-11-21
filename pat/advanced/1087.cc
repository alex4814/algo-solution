#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 205
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct City {
	char s[4];
	int h;
	bool operator < (const City &b) const {
		return strcmp(s, b.s) < 0;
	}
};

int n, k;
int r_c, r_h, r_ah, r_cnt;
int i_c, i_h, i_ah;
int g[MAXN][MAXN];
bool v[MAXN];
City c[MAXN];
deque<int> i_path, r_path;

inline int index_of(char *s) {
	int l = 0, r = n;
	while (l < r) {
		int m = l + (r - l) / 2;
		int p = strcmp(c[m].s, s);
		if (p == 0) return m;
		p < 0 ? l = m + 1 : r = m;
	}
	return -1;
}

void dfs(int s, int t) {
	if (s == t) {
		i_ah = i_h / (int)i_path.size();
		if (i_c < r_c) {
			r_c = i_c;
			r_h = i_h;
			r_ah = i_ah;
			r_path = i_path;
			r_cnt = 1;
		} else if (i_c == r_c) {
			r_cnt += 1;
			if (i_h > r_h || (i_h == r_h && i_ah > r_ah)) {
				r_h = i_h;
				r_ah = i_ah;
				r_path = i_path;
			}
		}
		return;
	}
	v[s] = true;
	i_path.push_back(s);
	for (int i = 0; i < n; ++i) {
		if (!v[i] && g[s][i]) {
			i_c += g[s][i];
			i_h += c[i].h;
			dfs(i, t);
			i_h -= c[i].h;
			i_c -= g[s][i];
		}
	}
	i_path.pop_back();
	v[s] = false;
}

int main() {
	char start[4];
	char dest[4] = "ROM";
	scanf("%d %d %s", &n, &k, start);
	for (int i = 1; i < n; ++i) {
		scanf("%s %d", c[i].s, &c[i].h);
	}
	strcpy(c[0].s, start);
	sort(c, c + n);
	int s = index_of(start);
	int t = index_of(dest);
	for (int i = 0, w; i < k; ++i) {
		char u[4], v[4];
		scanf("%s %s %d", u, v, &w);
		int p = index_of(u);
		int q = index_of(v);
		g[p][q] = g[q][p] = w;
	}
	r_c = INT_MAX;
	dfs(s, t);
	printf("%d %d %d %d\n", r_cnt, r_c, r_h, r_ah);
	int sz = r_path.size();
	for (int i = 0; i < sz; ++i) {
		printf("%s->", c[ r_path[i] ].s);
	}
	printf("ROM\n");
	return 0;
}


