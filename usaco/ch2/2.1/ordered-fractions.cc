/*
ID: alex4814
LANG: C++
TASK: frac1
*/

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
#define MAXN 165
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

struct Fraction {
	int n;
	int d;
	bool operator < (const Fraction &b) const {
		return n * b.d < d * b.n;
	}
	bool operator == (const Fraction &b) const {
		return n * b.d == d * b.n;
	}
	void reduce() {
		int a = n, b = d;
		while (a ^= b ^= a ^= b %= a);
		n /= b, d /= b;
	}
};

int n, fn;
Fraction f[MAXN * MAXN];

int main() {
#ifdef FILEIO
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			(f[fn++] = (Fraction){ i, j }).reduce();
		}
	}
	sort(f, f + fn);

	printf("0/1\n");
	if (fn) printf("%d/%d\n", f[0].n, f[0].d);
	for (int i = 1; i < fn; ++i) {
		if (f[i] == f[i - 1]) continue;
		printf("%d/%d\n", f[i].n, f[i].d);
	}
	printf("1/1\n");

	return 0;
}


