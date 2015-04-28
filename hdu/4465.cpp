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
#define _N 400005
#define _M 105
#define PI acos(-1.0)

int n;
double p;
double lnf[_N];

inline double logC(int n, int m)
{
	return lnf[n] - lnf[n - m] - lnf[m];
}
void init()
{
	lnf[0] = 0;
	FOR (i, 1, _N) { lnf[i] = lnf[i - 1] + log(i + 0.0); }
}

int main()
{
	init();
	int n_case = 0;
	while (scanf("%d%lf", &n, &p) == 2) {
		double result = 0;
		double log_p = log(p), log_q = log(1 - p);
		FOR (k, 0, n + 1) {
			result += (n - k) * ( exp(logC(n + k, k) + (n + 1) * log_p + k * log_q) + 
							      exp(logC(n + k, k) + (n + 1) * log_q + k * log_p) );
		}
		printf("Case %d: %.6f\n", ++n_case, result);
	}
	return 0;
}
