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

typedef long long ll;
int event[MAXN];

ll solve(int n, ll s, ll f)
{
	ll cost = f;
	for (int i = 1; i < n; ++i) {
		ll days = event[i] - event[i - 1] - 1;
		ll salary = days * s;
		if (salary < 2 * f) {
			cost += salary;
		} else {
			cost += 2 * f;
		}
	}
	return cost + s * n + f;
}

int main()
{
	int t, n, a, b;
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c) {
		scanf("%d%d%d", &n, &a, &b);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &event[i]);
		}
		printf("Case #%d: %lld\n", c, solve(n, (ll)b, (ll)a));
	}
	return 0;
}
