#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 505
#define MAXM 105

int n, m, c1, c2;
int g[MAXN][MAXN], w[MAXN], v[MAXN];
int dis, min_dis = 0x7fffffff, cnt, max_ret;
deque<int> path;

int gather_all() {
	int ret = 0;
	for (int i = 0; i < path.size(); ++i) {
		ret += w[path[i]];
	}
	return ret;
}

void dfs(int s) {
	if (s == c2) {
		if (dis < min_dis) {
			cnt = 1;
			min_dis = dis;
			max_ret = gather_all();
		} else if (dis == min_dis) {
			++cnt;
			max_ret = max(max_ret, gather_all());
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!v[i] && g[s][i]) {
			v[i] = 1;
			path.push_back(i);
			dis += g[s][i];
			dfs(i);
			dis -= g[s][i];
			path.pop_back();
			v[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w[i]);
	}
	for (int i = 0, a, b, c; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = c;
	}

	v[c1] = 1;
	path.push_back(c1);
	dfs(c1);

	printf("%d %d\n", cnt, max_ret);
	return 0;
}
