/*
ID: alex4814
LANG: C++
TASK: nocows
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
#define MAXN 205
#define MAXK 105
#define MOD 9901

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int f[MAXN][MAXK];

bool gt(int n, int k) {
	int r = 1;
	for (int i = 0; i < k; ++i) {
		r <<= 1;
		if (r > n) return false;
	}
	return true;
}

int cal(int n, int k) {
	if (f[n][k] != -1) return f[n][k];
	if (n == 1) return f[n][k] = (k == 1 ? 1 : 0);
	int ret = 0;
	for (int l = 1; l < n; l += 2) {
		int r = n - 1 - l;
		for (int h = 0; h < k - 1; ++h) {
			ret = (ret + cal(l, k - 1) * cal(r, h)) % MOD;
			ret = (ret + cal(r, k - 1) * cal(l, h)) % MOD;
		}
		ret = (ret + cal(l, k - 1) * cal(r, k - 1)) % MOD;
	}
	return f[n][k] = ret;
}

int main() {
#ifdef FILEIO
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	if (!(n & 1) || gt(n, k)) {
		printf("0\n");
	} else {
		memset(f, -1, sizeof(f));
		printf("%d\n", cal(n, k));
	}
	return 0;
}


