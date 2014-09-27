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
#define MAXN 1005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

struct MoonCake {
	double q, p;
	bool operator < (const MoonCake &b) const {
		return sgn(p * b.q - q * b.p) > 0;
	}
};

MoonCake mc[MAXN];

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &mc[i].q);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &mc[i].p);
	}
	sort(mc, mc + n);
	double rest = r;
	double totp = 0;
	for (int i = 0; i < n; ++i) {
		if (sgn(rest) == 0) break;
		if (sgn(rest - mc[i].q) >= 0) {
			rest -= mc[i].q;
			totp += mc[i].p;
		} else {
			totp += rest * mc[i].p / mc[i].q;
			rest = 0;
		}
	}
	printf("%.2f\n", totp);
	return 0;
}


