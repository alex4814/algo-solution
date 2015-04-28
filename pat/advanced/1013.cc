#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 1005
#define MAXM 105

int n, m, k;
int a, b, c;
int g[MAXN][MAXN];
int v[MAXN];

void dfs(int s) {
	for (int i = 0; i < n; ++i) {
		if (!v[i] && g[s][i]) {
			v[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b); --a, --b;
		g[a][b] = g[b][a] = 1;
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", &c); --c;
		memset(v, 0, sizeof(v));

		v[c] = 1;
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (!v[j]) { dfs(j); ++cnt; }
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}
