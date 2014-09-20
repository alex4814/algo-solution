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

#define FILEIO
int o[MAXN][MAXN];
int g[MAXN][MAXN];

int owns(int u, int v) {
	if (o[u][v] != -1) return o[u][v];
	//printf("%d %d\n", u, v);
	if (u == v) return o[u][v] = 1;
	if (g[u][v] > 50) return o[u][v] = 1;
	int tot = 0;
	for (int i = 1; i < MAXN; ++i) {
		if (i != v && (o[u][i] == 1 || (g[u][i] && owns(u, i)))) {
			tot += g[i][v];
		}
	}
	return o[u][v] = (tot > 50);
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
	}
	memset(o, -1, sizeof(o));
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 1; j < MAXN; ++j) {
			if (i != j && owns(i, j)) {
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}


