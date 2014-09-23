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

int a[MAXN];

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int r = 0;
	for (int i = 0; i < n; ++i) {
		ll m = (ll)a[i] * p;
		int j = upper_bound(a, a + n, m) - a;
		r = max(r, j - i);
	}
	printf("%d\n", r);
	return 0;
}


