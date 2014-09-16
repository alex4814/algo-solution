#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 1005
#define MAXM 105

int a[MAXN], f[MAXN];

void cal(int ix, int l, int r) {
	if (l > r) return;
	if (l == r) {
		f[ix] = a[l]; return;
	}
	int n = r - l + 1;
	int lv = log2(n), ln, rn;
	int leaf = n - (1 << lv) + 1; 
	//printf("leaf = %d\n", leaf);
	if (leaf > (1 << (lv - 1))) {
		ln = (1 << lv) - 1;
		rn = n - ln - 1;
	} else {
		ln = (1 << (lv - 1)) - 1 + leaf;
		rn = n - ln - 1;
	}
	//printf("ln = %d, rn = %d\n", ln, rn);
	f[ix] = a[l + ln];
	cal(ix << 1, l, l + ln - 1);
	cal(ix << 1 | 1, l + ln + 1, r);
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	cal(1, 1, n);

	for (int i = 1; i < n; ++i) {
		printf("%d ", f[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}
