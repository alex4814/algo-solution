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
#define MAXN 55
#define MAXM 105

int n, m;
char st[MAXN][MAXM];

int main() {
	while (scanf("%d", &n), n >= 0) {
		scanf("%d", &m);
		FOR (i, 0, n) { fgets(st[i], MAXM, stdin); }
		FOR (i, 0, m) { fgets(nd[i], MAXM, stdin); }
	}
	return 0;
}
