/*
ID: alex4814
LANG: C++
TASK: hamming
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
#define MAXN 64
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n, b, d;
int r[MAXN], nr;

int ones(int x) {
	int ret = 0;
	for (int i = 0; i < b; ++i) {
		if (x & (1 << i)) ret++;
	}
	return ret;
}

inline bool ok(int p, int q) {
	return ones(p ^ q) >= d;
}

int main() {
#ifdef FILEIO
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
#endif

	scanf("%d %d %d", &n, &b, &d);
	const int tot = 1 << b;
	r[nr++] = 0;
	for (int i = 1, k; i < tot; ++i) {
		if (nr == n) break;
		for (k = 0; k < nr; ++k) {
			if (!ok(i, r[k])) break;
		}
		if (k == nr) r[nr++] = i;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", r[i], (i % 10 == 9) || (i + 1 == n) ? '\n' : ' ');
	}

	return 0;
}


