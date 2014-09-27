#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define EPS 1e-8
#define MAXN 1005
#define PI acos(-1.0)

int v[MAXN], dp[MAXN];
int n, m;

void zero_one_pack(int value, int cost)
{
	for (int v = m; v >= cost; --v) {
		dp[v] = max(dp[v], dp[v - cost] + value);
	}
}

int main()
{
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		scanf("%d", &m);

		if (m < 5) {
			printf("%d\n", m);
			continue;
		}

		memset(dp, 0, sizeof(dp));
		sort(v, v + n);
		for (int i = 0; i < n - 1; ++i) {
			zero_one_pack(v[i], v[i]);
		}
		printf("%d\n", m - dp[m - 5] - v[n - 1]);
	}
	return 0;
}
