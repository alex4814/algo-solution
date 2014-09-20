/*
ID: alex4814
LANG: C++
TASK: holstein
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
#define MAXN 30
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n, m;
int v[MAXN];
int g[MAXN][MAXN];
int d[MAXN], nd;

bool ok(int p) {
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			if (p & (1 << j)) sum += g[j][i];
		}
		if (sum < v[i]) return false;
	}
	return true;
}

int number(int p, int *a) {
	int c = 0;
	for (int i = 0; i < m; ++i) {
		if (p & (1 << i)) {
			a[c++] = i + 1;
		}
	}
	return c;
}

bool update(int r, int p) {
	int rr[MAXN], pp[MAXN];
	int nr = number(r, rr);
	int np = number(p, pp);
	if (np < nr) return true;
	if (np == nr && pp[0] < rr[0]) return true;
	return false;
}

int main() {
#ifdef FILEIO
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &g[i][j]);
		}
	}

	int ret = (1 << m) - 1;
	const int tot = 1 << m;
	for (int p = 0; p < tot; ++p) {
		if (ok(p) && update(ret, p)) {
			ret = p;
		}
	}

	nd = number(ret, d);
	printf("%d", nd);
	for (int i = 0; i < nd; ++i) {
		printf(" %d", d[i]);
	}
	putchar('\n');

	return 0;
}


