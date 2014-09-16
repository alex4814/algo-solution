#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 100005
#define MAXM 105

double rate[3][3], m[3];
char r[3], l[3] = {'W','T','L'};

int main() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%lf", &rate[i][j]);
			rate[i][j] > m[i] ? m[i] = rate[i][j], r[i] = l[j] : 0;
		}
	}
	double ret = 1.0;
	for (int i = 0; i < 3; ++i) {
		printf("%c ", r[i]);
		ret *= m[i];
	}
	printf("%.2f\n", (ret * 0.65 - 1.0) * 2.0);
	return 0;
}
