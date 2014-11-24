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

int dist[MAXN][MAXN];
int cost[MAXN][MAXN];

bool vis[MAXN];
int d[MAXN];	// distance
int c[MAXN];	// cost
int f[MAXN];	// father

void dijkstra(int s, int n) {
	memset(vis, 0, sizeof(vis));
	memset(f, -1, sizeof(f));
	for (int i = 0; i < n; ++i) {
		c[i] = d[i] = INF;
	}
	c[s] = d[s] = 0;
	for (int i = 0; i < n; ++i) {
		int x, m = INF;
		for (int y = 0; y < n; ++y) {
			if (!vis[y] && d[y] <= m) {
				m = d[x = y];
			}
		}
		vis[x] = true;
		for (int y = 0; y < n; ++y) {
			if (d[y] > d[x] + dist[x][y]) {
				d[y] = d[x] + dist[x][y];
				c[y] = c[x] + cost[x][y];
				f[y] = x;
			} else if (d[y] == d[x] + dist[x][y]) {
				if (c[y] > c[x] + cost[x][y]) {
					c[y] = c[x] + cost[x][y];
					f[y] = x;
				}
			}
		}
	}
}

void print(int x) {
	if (x == -1) {
		return;
	}
	print(f[x]);
	printf("%d ", x);
}

int main() {
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; ++i) {
		int u, v, w, c;
		scanf("%d %d %d %d", &u, &v, &w, &c);
		dist[u][v] = dist[v][u] = w;
		cost[u][v] = cost[v][u] = c;
	}
	dijkstra(s, n);
	print(t);
	printf("%d %d\n", d[t], c[t]);
	return 0;
}


