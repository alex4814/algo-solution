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
#define MAXN 505
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct Station {
    double d, p;
	bool operator < (const Station &b) const {
		return d < b.d;
	}
};
Station s[MAXN];
double C, D, d;
int n;

bool reach(double &dis) {
	if (s[0].d != 0) return false;
	for (int i = 0; i < n; ++i) {
		dis = s[i].d + d * C;
		if (dis >= D) return true;
		if (i + 1 < n && dis < s[i + 1].d) return false;
		if (i + 1 == n && dis < D) return false;
	}
	return true;
}

int station2choose(int ix) {
	if (ix + 1 == n) return -1;
	if (s[ix].p > s[ix + 1].p) return ix + 1;
	double maxd = s[ix].d + C * d;
	double minp = 1e20;
	int j;
	for (int i = ix + 1; i < n; ++i) {
		if (s[i].d > maxd) break;
		if (s[i].p < s[ix].p) return i;
		if (s[i].p < minp) {
			minp = s[i].p;
			j = i;
		}
	}
	if (maxd > D) return -1;
	return j;
}

int main() {
	scanf("%lf %lf %lf %d", &C, &D, &d, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf", &s[i].p, &s[i].d);
	}

	sort(s, s + n);
	double X = 0;
	if (reach(X)) {
		double p = 0, curc = 0, c;
		for (int i = 0, ix; i < n; i = ix) {
			ix = station2choose(i);
			if (ix == -1) {
				c = (D - s[i].d) / d;
				p += (c - curc) * s[i].p;
				break;
			} else if (s[i].p < s[ix].p) {
				p += (C - curc) * s[i].p;
				c = (s[ix].d - s[i].d) / d;
				curc = C - c;
			} else {
				c = (s[ix].d - s[i].d) / d;
				if (curc >= c) {
					curc -= c;
				} else {
					p += s[i].p * (c - curc);
					curc = 0;
				}
			}
		}
		printf("%.2f\n", p);
	} else {
		printf("The maximum travel distance = %.2f\n", X);
	}

	return 0;
}


