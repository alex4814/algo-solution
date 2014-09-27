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

int n, m, l, t;
int tc[105], v[105];
int dp[105][105][1005];

int zero_one_pack(int i, int time_cost, int value)
{
	for (int s = 1; s < m; ++s) {
		for (int v = time_cost; v <= l; ++v) {
			dp[i][s][v] = max(dp[i - 1][s][v], 
							  dp[i - 1][s - 1][v - time_cost] + value);
		}
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m, &l);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &tc[i], &v[i]);
		}

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			zero_one_pack(i + 1, tc[i], v[i]);
		}
		printf("%d\n", dp[n - 1][m][l]);
	}
	return 0;
}
