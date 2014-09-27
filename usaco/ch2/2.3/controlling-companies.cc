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
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 105
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

//#define FILEIO

int o[MAXN][MAXN];
int g[MAXN][MAXN];
int in[MAXN];

int owns(int u, int v) {
	if (o[u][v] != -1) return o[u][v];
	if (u == v || g[u][v] > 50) return o[v][u] = 0, o[u][v] = 1;
	int tot = 0;
	printf("%d %d\n", u, v);
	for (int k = 1; k < MAXN; ++k) {
		if (k == u || k == v || !in[k]) continue;
		if ((o[u][k] = owns(u, k)) == 1) {
			tot += g[u][k];
		}
		if (tot > 50) {
			o[v][u] = 0;
			return o[u][v] = 1;
		}
	}
	return o[u][v] = 0;
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
		g[u][v] = p;
		in[u] = in[v] = 1;
	}
	memset(o, -1, sizeof(o));
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 1; j < MAXN; ++j) {
			if (i == j || !in[i] || !in[j]) continue;
			if ((o[i][j] = owns(i, j)) == 1) {
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}


