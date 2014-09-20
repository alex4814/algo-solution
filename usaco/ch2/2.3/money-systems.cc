/*
ID: alex4814
LANG: C++
TASK: money
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
#define MAXN 10005
#define MAXV 30

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO
int c[MAXV];
ll f[MAXN];

int main() {
#ifdef FILEIO
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
#endif
	int v, n;
	scanf("%d %d", &v, &n);
	for (int i = 0; i < v; ++i) {
		scanf("%d", c + i);
	}
	f[0] = 1;
	for (int k = 0; k < v; ++k) {
		for (int i = n; i > 0; --i) {
			for (int j = 1; i - j * c[k] >= 0; ++j) {
				f[i] += f[i - j * c[k]];
			}
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}


