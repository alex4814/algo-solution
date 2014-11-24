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

int d[MAXN << 1];
int s[MAXN << 1];

int shortest(int u, int v, int n) {
	if (u > v) {
		swap(u, v);
	}
	int da = s[v] - s[u];
	int db = s[u + n] - s[v];
	return min(da, db);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", d + i);
		d[i + n] = d[i];
	}
	s[0] = 0;
	for (int i = 1; i <= n << 1; ++i) {
		s[i] = s[i - 1] + d[i - 1];
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", shortest(u - 1, v - 1, n));
	}
	return 0;
}


