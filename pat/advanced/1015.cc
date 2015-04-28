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

int n, d;
int p[MAXN], np, f[MAXN];

void get_primes() {
	f[0] = f[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		if (!f[i]) p[np++] = i;
		for (int j = 0; j < np && p[j] * i < MAXN; ++j) {
			f[p[j] * i] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

int convert() {
	int dig[100], nd = 0;
	while (n > 0) {
		dig[nd++] = n % d;
		n /= d;
	}
	int ret = 0;
	for (int i = 0; i < nd; ++i) {
		ret = ret * d + dig[i];
	}
	return ret;
}

int main() {
	get_primes();
	while (scanf("%d", &n), n >= 0) {
		scanf("%d", &d);
		!f[n] && !f[ convert() ] ? puts("Yes") : puts("No");
	}
	return 0;
}
