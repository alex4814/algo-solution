#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 10005
#define MAXM 105

int n, cnt, c, d;
vector<int> g[MAXN];
int vis[MAXN], depth[MAXN];

void dfs(int s, int dep) {
	d = max(d, dep);
	vis[s] = 1;
	for (int i = 0; i < g[s].size(); ++i) {
		if (!vis[g[s][i]]) {
			dfs(g[s][i], dep + 1);
		}
	}
}

int root(int s) {
	cnt = 1;
	dfs(s, 0);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) { dfs(i, 0); ++cnt; }
	}
	return cnt > 1 ? -1 : d;
}

int main() {
	scanf("%d", &n);
	for (int i = 0, a, b; i < n - 1; ++i) {
		scanf("%d%d", &a, &b); --a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int max_d = 0;
	for (int i = 0; i < n; ++i) {
		cnt = d = 0;
		memset(vis, 0, sizeof(vis));
		if ((depth[i] = root(i)) == -1) {
			printf("Error: %d components\n", cnt);
			return 0;
		}
		max_d = max(max_d, depth[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (depth[i] == max_d) {
			printf("%d\n", i + 1);
		}
	}
	return 0;
}
