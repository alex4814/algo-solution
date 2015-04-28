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

int n;
int q[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &q[i]);
	}
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		tot += abs(q[i] - q[i - 1]) * (q[i] > q[i - 1] ? 6 : 4) + 5;
	}
	printf("%d\n", tot);
	return 0;
}
