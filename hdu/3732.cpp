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
#define MAXN 100005
#define PI acos(-1.0)

int n, V;
char s[20];
int v[121], w[121], m[121];
int dp[MAXN];

void zero_one_pack(int cost, int value)
{
	for (int v = V; v >= cost; --v) {
		dp[v] = max(dp[v], dp[v - cost] + value);
	}
}

void complete_pack(int cost, int value)
{
	for (int v = cost; v <= V; ++v) {
		dp[v] = max(dp[v], dp[v - cost] + value);
	}
}

void multiple_pack(int cost, int value, int num)
{
	if (cost * num >= V) {
		complete_pack(cost, value);
		return;
	}
	int k = 1;
	while (k < num) {
		zero_one_pack(k * cost, k * value);
		num = num - k;
		k <<= 1;
	}
	zero_one_pack(cost * num, value * num);
}

int main()
{
	while (scanf("%d%d", &n, &V) == 2) {
		memset(m, 0, sizeof(m));
		for (int i = 0, a, b; i < n; ++i) {
			scanf("%s%d%d", s, &a, &b);
			int t = a * 11 + b;
			v[t] = a, w[t] = b, m[t]++;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 121; ++i) {
			multiple_pack(w[i], v[i], m[i]);
		}
		printf("%d\n", dp[V]);
	}
	return 0;
}
