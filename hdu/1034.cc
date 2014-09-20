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
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int a[MAXN], b[MAXN];
int n;

int all_same() {
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) return 0;
	}
	return a[0];
}

int main() {
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		int r = 0, p;
		while (!(p = all_same())) {
			for (int i = 0; i < n; ++i) {
				b[i] = a[i] >> 1;
			}
			for (int i = 1; i <= n; ++i) {
				a[i % n] = a[i % n] - b[i % n] + b[i - 1];
				if (a[i % n] & 1) a[i % n]++;
			}
			++r;
		}
		printf("%d %d\n", r, p);
	}

	return 0;
}


