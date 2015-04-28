/*
ID: alex4814
LANG: C++
TASK: concom
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 105
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int g[MAXN][MAXN];
int o[MAXN][MAXN];
int c[MAXN];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == s) {
			c[x] = 100;
		}
		if (c[x] > 50) {
			o[s][x] = 1;
			for (int i = 0; i < MAXN; ++i) {
				if (g[x][i] && !o[s][i]) {
					c[i] += g[x][i];
					q.push(i);
				}
			}
		}
	}
}

int main() {
#ifdef FILEIO
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int u, v, p;
		scanf("%d %d %d", &u, &v, &p);
		g[--u][--v] = p;
	}
	for (int i = 0; i < MAXN; ++i) {
		memset(c, 0, sizeof(c));
		bfs(i);
	}
	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			if (i == j || o[i][j] == 0) {
				continue;
			}
			printf("%d %d\n", i + 1, j + 1);
		}
	}
	return 0;
}


