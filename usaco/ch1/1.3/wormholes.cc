/*
ID: alex4814
LANG: C++
TASK: wormhole
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
#define MAXN 13
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n;
int x[MAXN], y[MAXN];
int p[MAXN], v[MAXN];
int next_hole[MAXN];

int cycle_exists() {
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; ++i) {
		int pos = i;
		for (int c = 0; c < n; ++c) {
			pos = next_hole[ p[pos] ];
		}
		if (pos != n) {
			return 1;
		}
	}
	return 0;
}

int gao() {
	int i, j;
	// find unpaired i
	for (i = 0; i < n; ++i) {
		if (p[i] == -1) {
			break;
		}
	}

	if (i == n) {
		return cycle_exists();
	}
	
	int r = 0;
	for (j = i + 1; j < n; ++j) {
		if (p[j] == -1) {
			p[i] = j, p[j] = i;
			r += gao();
			p[i] = p[j] = -1;
		}
	}
	return r;
}

int main() {
#ifdef FILEIO
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", x + i, y + i);
	}
	memset(p, -1, sizeof(p));
	next_hole[n] = p[n] = n;
	for (int i = 0; i < n; ++i) {
		int k = n;
		for (int j = 0; j < n; ++j) {
			if (y[i] == y[j] && x[j] > x[i]) {
				if (k == n || x[j] < x[k]) {
					k = j;
				}
			}
		}
		next_hole[i] = k;
	}
	printf("%d\n", gao());
	return 0;
}


