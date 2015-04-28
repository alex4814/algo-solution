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
#define _N 100005
#define _M 105
#define PI acos(-1.0)

int notp[_N], p[_N], np;
int n;

void init(int x) {
	for (int i = 2; i <= x; ++i) {
		if (!notp[i]) {
			p[np++] = i;
		}
		for (int j = 0; j < np; ++j) {
			int k = i * p[j];
			if (k > n) break;
			notp[k] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

int main() {
	scanf("%d", &n);
	init(n);
	int ret = 0;
	for (int i = 1; i < np; ++i) {
		if (p[i] - p[i - 1] == 2) ++ret;
	}
	printf("%d\n", ret);
	return 0;
}
