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
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

ll part_of(ll x, int d) {
	ll r = 0;
	int n = 0;
	while (x > 0) {
		if (x % 10 == d) ++n;
		x /= 10;
	}
	for (int i = 0; i < n; ++i) {
		r = r * 10 + d;
	}
	return r;
}

int main() {
	ll a, b, pa, pb;
	int da, db;
	scanf("%lld %d %lld %d", &a, &da, &b, &db);
	pa = part_of(a, da);
	pb = part_of(b, db);
	printf("%lld\n", pa + pb);
	return 0;
}


