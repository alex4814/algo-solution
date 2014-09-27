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
#define PI acos(-1.0)

int p[MAXN], np;
int r[MAXN];
bool f[MAXN];

void get_primes() {
	np = 0;
	for (int i = 2; i <= MAXN; ++i) {
		if (!f[i]) { p[np++] = i; }
		for (int j = 0; j < np && p[j] * i <= MAXN; ++j) {
			f[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

void init() {
	int cur = 1;
	for (int i = 2; i < MAXN; ++i) {
		if (p[cur] > i) {
			r[i] = r[i - 1];
		} else if (p[cur] == i) {
			if (p[cur] - p[cur - 1] == 2) {
				r[i] = r[i - 1] + 1;
			} else {
				r[i] = r[i - 1];
			}
			++cur;
		}
	}
}

int main() {
	get_primes();
	init();

	int n;
	while (scanf("%d", &n), n >= 0) {
		printf("%d\n", r[n]);
	}
	return 0;
}
