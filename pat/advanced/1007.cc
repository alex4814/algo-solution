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
#define MAXN 10005
#define MAXM 105

int n, b, nb, e;
int a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int ret = -1, s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
		if (s > ret) {
			ret = s;
			e = i;
			b = nb;
		}
		if (s < 0) {
			s = 0;
			nb = i + 1;
		}
	}
	ret == -1 ? printf("0 %d %d\n", a[0], a[n - 1]) : printf("%d %d %d\n", ret, a[b], a[e]);
	return 0;
}
