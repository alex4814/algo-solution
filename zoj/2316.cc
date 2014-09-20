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
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int T, n, m;
int c[MAXN];

int main() {
	scanf("%d", &T);

	for (int nCase = 1; nCase <= T; ++nCase) {
		memset(c, 0, sizeof(c));

		scanf("%d %d", &n, &m);
		for (int i = 0, a, b; i < m; ++i) {
			scanf("%d %d", &a, &b);
			c[a]++, c[b]++;
		}

		int ret = 0;
		for (int i = 1; i <= n; ++i) {
			ret += c[i] * (c[i] - 1) / 2;
		}

		printf("%d\n", ret + m << 1);
		if (nCase != T) putchar('\n');
	}

	return 0;
}


