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
#define MAXE 20005

typedef pair<int, int> pii;
typedef long long ll;

int T, n, m;
int bin[MAXN], bout[MAXN];
int uu[MAXE], vv[MAXE];

// Max Flow (Edmonds-Karp Algorithm)
// - nodes numbered from 1 to n
int b[MAXN][MAXN];
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int p[MAXN];	// parent
int rsd[MAXN];	// minimum residual of one augmenting path
queue<int> q;

int max_flow(int s, int t) {
	int f = 0;
	memset(flow, 0, sizeof(flow));

	while (1) {
		memset(rsd, 0, sizeof(rsd));
		rsd[s] = INT_MAX;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v = 0; v <= n + 1; ++v) {
				if (!rsd[v] && cap[u][v] > flow[u][v]) {
					p[v] = u; q.push(v);
					rsd[v] = min(rsd[u], cap[u][v] - flow[u][v]);
				}
			}
		}
		if (rsd[t] == 0) break;
		for (int u = t; u != s; u = p[u]) {
			flow[ p[u] ][u] += rsd[t];
			flow[u][ p[u] ] -= rsd[t];
		}
		f += rsd[t];
	}
	return f;
}

bool has_solution() {
	for (int i = 1; i <= n; ++i) {
		if (flow[0][i] != cap[0][i]) return false;
	}
	return true;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		memset(bin, 0, sizeof(bin));
		memset(bout, 0, sizeof(bout));
		memset(b, 0, sizeof(b));
		memset(cap, 0, sizeof(cap));

		scanf("%d %d", &n, &m);
		for (int i = 0, u, v; i < m; ++i) {
			scanf("%d %d", &u, &v);
			scanf("%d %d", &b[u][v], &cap[u][v]);
			uu[i] = u, vv[i] = v;
			cap[u][v] -= b[u][v];
			bin[v] += b[u][v];
			bout[u] += b[u][v];
		}
		
		for (int i = 1; i <= n; ++i) {
			if (bin[i] - bout[i] >= 0) {
				cap[0][i] = bin[i] - bout[i];
			} else {
				cap[i][n + 1] = bout[i] - bin[i];
			}
		}

		max_flow(0, n + 1);
		if (has_solution()) {
			printf("YES\n");
			for (int i = 0; i < m; ++i) {
				printf("%d\n", flow[ uu[i] ][ vv[i] ] + b[ uu[i] ][ vv[i] ]);
			}
		} else {
			printf("NO\n");
		}

		putchar('\n');
	}

	return 0;
}


