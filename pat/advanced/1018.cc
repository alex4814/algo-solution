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
#define MAXN 505
#define MAXE 1005
#define INF 0x3f3f3f3f

typedef pair<int, int> pii;
typedef long long ll;

int C, dest;
int g[MAXN][MAXN];
int c[MAXN];

int coll, r_coll;
int sent, r_sent; 
int dis, r_dis;
vector<int> p, r_p;
bool vis[MAXN];

void dfs(int x, int n) {
	if (dis > r_dis) {
		return;
	}
	if (x == dest) {
		if ((dis < r_dis) ||
				(dis == r_dis && sent < r_sent) ||
				(dis == r_dis && sent == r_sent && coll < r_coll)) {
			r_dis = dis;
			r_sent = sent;
			r_coll = coll;
			r_p = p;
		}
		return;
	}
	vis[x] = true;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i] && g[x][i] > 0) {
			dis += g[x][i];
			p.push_back(i);
			int ss = sent;
			int cc = coll;
			if (c[i] > C) {
				coll += c[i] - C;
			} else {
				sent += max((C - c[i]) - coll, 0);
				coll = max(coll - (C - c[i]), 0);
			}
			dfs(i, n);
			sent = ss;
			coll = cc;
			p.pop_back();
			dis -= g[x][i];
		}
	}
	vis[x] = false;
}

int main() {
	int n, m;
	scanf("%d %d %d %d", &C, &n, &dest, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i);
	}
	fill(g[0], g[n + 1], INF);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	r_dis = INF;
	r_sent = 0;
	r_coll = 0;
	C >>= 1;
	dfs(0, n);
	printf("%d 0", r_sent);
	int sz = r_p.size();
	for (int i = 0; i < sz; ++i) {
		printf("->%d", r_p[i]);
	}
	printf(" %d\n", r_coll);
	return 0;
}


