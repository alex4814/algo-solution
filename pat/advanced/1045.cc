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
#define MAXN 10005
#define MAXC 205

typedef pair<int, int> pii;
typedef long long ll;

int fc[MAXC];
int sc[MAXN];
int mapping[MAXC];
int a[MAXN], na;
int f[MAXN], nf;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", fc + i);
		mapping[ fc[i] ] = i;
	}
	int k;
	scanf("%d", &k);
	m = 0;
	for (int i = 0; i < k; ++i) {
		scanf("%d", sc + i);
		if (mapping[ sc[i] ]) {
			a[m++] = mapping[ sc[i] ];
		}
	}
	for (int i = 0; i < m; ++i) {
		int ix = upper_bound(f, f + nf, a[i]) - f;
		if (ix == nf) {
			f[nf++] = a[i];
		} else if (a[i] < f[ix]) {
			f[ix] = a[i];
		}
	}
	printf("%d\n", nf);
	return 0;
}


