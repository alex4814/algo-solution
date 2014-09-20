/*
ID: alex4814
LANG: C++
TASK: castle
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
#define MAXV 55
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n, m;
int a[MAXV][MAXV];
int v[MAXV][MAXV];
int sz[MAXV * MAXV];
int nc, ns, rns, rwx, rwy;
char rwd;

void print(int d[MAXV][MAXV]) {
	putchar('\n');
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", d[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void dfs(int x, int y, int cpn) {
	v[x][y] = cpn;
	if (y > 0 && !(a[x][y] & 1) && !v[x][y - 1]) dfs(x, y - 1, cpn);
	if (x > 0 && !(a[x][y] & 2) && !v[x - 1][y]) dfs(x - 1, y, cpn);
	if (y < m - 1 && !(a[x][y] & 4) && !v[x][y + 1]) dfs(x, y + 1, cpn);
	if (x < n - 1 && !(a[x][y] & 8) && !v[x + 1][y]) dfs(x + 1, y, cpn);
}

int num_component() {
	int ret = 0;
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]) continue;
			dfs(i, j, ++ret);
		}
	}
	//print(v);
	return ret;
}

int lsize_component(int nc) {
	int ret = 0;
	memset(sz, 0, sizeof(sz));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sz[ v[i][j] ]++;
		}
	}
	for (int i = 1; i <= nc; ++i) {
		ret = max(ret, sz[i]);
	}
	return ret;
}


int main() {
#ifdef FILEIO
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
#endif
	int tsz;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	nc = num_component();
	ns = lsize_component(nc);

	rns = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0 && (a[i][j] & 2)) {
				a[i][j] &= ~2;
				a[i - 1][j] &= ~8;
				//print(a);
				tsz = lsize_component(num_component());
				if (tsz > rns) {
					rns = tsz, rwx = i, rwy = j, rwd = 'N';
				} else if (tsz == rns) {
					if (j < rwy || (j == rwy && i > rwx)) {
						rwx = i, rwy = j, rwd = 'N';
					}
				}
				a[i][j] |= 2;
				a[i - 1][j] |= 8;
				//printf("%d %d %c: %d\n", i + 1, j + 1, 'N', tsz);
			}
			if (j < m - 1 && (a[i][j] & 4)) {
				a[i][j] &= ~4;
				a[i][j + 1] &= ~1;
				//print(a);
				tsz = lsize_component(num_component());
				if (tsz > rns) {
					rns = tsz, rwx = i, rwy = j, rwd = 'E';
				} else if (tsz == rns) {
					if (j < rwy || (j == rwy && i > rwx)) {
						rwx = i, rwy = j, rwd = 'E';
					}
				}
				a[i][j] |= 4;
				a[i][j + 1] |= 1;
				//printf("%d %d %c: %d\n", i + 1, j + 1, 'E', tsz);
			}
		}
	}
	
	printf("%d\n%d\n", nc, ns);
	printf("%d\n%d %d %c\n", rns, rwx + 1, rwy + 1, rwd);
	
	return 0;
}


