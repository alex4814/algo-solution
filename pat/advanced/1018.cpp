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

int c_max, n, dest, m;
int vis[MAXN];
int g[MAXN][MAXN], c[MAXN];
int min_back, tot_sent;
int min_dis = 0x7fffffff, dis;
deque<int> p, path;

int cal_back() {
	int sent = 0, cur = 0;
	for (int i = 1; i < p.size(); ++i) {
		if (c[p[i]] > c_max / 2) {
			cur += c[p[i]] - c_max / 2;
		} else if (c[p[i]] + cur < c_max / 2) {
			sent += c_max / 2 - c[p[i]] - cur;
			cur = 0;
		} else {
			cur -= c_max / 2 - c[p[i]];
		}
	}
	return cur;
}

int cal_sent() {
	int sent = 0, cur = 0;
	for (int i = 1; i < p.size(); ++i) {
		if (c[p[i]] > c_max / 2) {
			cur += c[p[i]] - c_max / 2;
		} else if (c[p[i]] + cur < c_max / 2) {
			sent += c_max / 2 - c[p[i]] - cur;
			cur = 0;
		} else {
			cur -= c_max / 2 - c[p[i]];
		}
	}
	return sent;
}

void dfs(int ix) {
	int back, sent;
	if (ix == dest) {
		if (dis < min_dis) {
			min_dis = dis;
			min_back = cal_back();
			tot_sent = cal_sent();
		} else if (dis == min_dis) {
			if ((back = cal_back()) < min_back) { 
				min_back = back;
				tot_sent = cal_sent();
				path = p;
			} else if (back == min_back && (sent = cal_sent()) < tot_sent) {
				tot_sent = sent;
				path = p;
			}
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i] && g[ix][i]) {
			vis[i] = 1;
			p.push_back(i);
			dis += g[ix][i];
			dfs(i);
			dis -= g[ix][i];
			p.pop_back();
			vis[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d%d%d", &c_max, &n, &dest, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	for (int i = 0, u, v, w; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}

	vis[0] = 1;
	p.push_back(0);
	dfs(0);

	printf("%d 0", tot_sent);
	for (int i = 1; i < path.size(); ++i) {
		printf("->%d", path[i]);
	}
	printf(" %d\n", min_back);
	return 0;
}
