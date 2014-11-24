#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 1005
#define MAXM 105

int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

int n, e;
double c;
double coef[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%lf", &e, &c);
		coef[e] += c;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%lf", &e, &c);
		coef[e] += c;
	}
	int cnt = 0;
	for (int i = 1000; i >= 0; --i) {
		if (sgn(coef[i]) != 0) ++cnt;
	}
	printf("%d", cnt);
	for (int i = 1000; i >= 0; --i) {
		if (sgn(coef[i]) != 0) {
			printf(" %d %.1f", i, coef[i]);
		}
	}
	printf("\n");
	return 0;
}
