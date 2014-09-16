#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 1000005
#define MAXM 105

int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

int n, e;
double c;
map<int, double> a, b, ret;
map<int, double>::iterator it1, it2;
map<int, double>::reverse_iterator it;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%lf", &e, &c);
		a[e] = c;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%lf", &e, &c);
		b[e] = c;
	}
	
	for (it1 = a.begin(); it1 != a.end(); ++it1) {
		for (it2 = b.begin(); it2 != b.end(); ++it2) {
			ret[it1->first + it2->first] += it1->second * it2->second;
		}
	}
	int cnt = 0;
	for (it = ret.rbegin(); it != ret.rend(); ++it) {
		if (sgn(it->second) != 0) {
			++cnt;
		}
	}
	printf("%d", cnt);
	for (it = ret.rbegin(); it != ret.rend(); ++it) {
		if (sgn(it->second) != 0) {
			printf(" %d %.1f", it->first, it->second);
		}
	}
	printf("\n");
	return 0;
}

