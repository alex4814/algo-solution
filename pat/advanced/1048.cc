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
#define MAXV 505

typedef pair<int, int> pii;
typedef long long ll;

int v[MAXN];
int cnt[MAXV];

int bins(int *a, int n, int key) {
	int l = 0, r = n;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (a[m] == key) return m;
		a[m] > key ? r = m : l = m + 1;
	}
	return -1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
		cnt[ v[i] ] += 1;
	}
	sort(v, v + n);
	for (int i = 0; i < n; ++i) {
		int x = bins(v, n, m - v[i]);
		if (x == -1 || (x == i && cnt[ v[x] ] <= 1)) {
			continue;
		}
		printf("%d %d\n", v[i], v[x]);
		return 0;
	}
	printf("No Solution\n");
	return 0;
}


