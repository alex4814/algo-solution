/*
ID: alex4814
LANG: C++
TASK: sort3
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
#define MAXN 1005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n;
int a[MAXN];
int b[MAXN];
int c[4][4];

int main() {
#ifdef FILEIO
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		b[i] = a[i];
	}
	sort(b, b + n);

	int ret = 0, dif = 0;
	for (int i = 0; i < n; ++i) {
		c[ a[i] ][ b[i] ]++;
	}
	ret += min(c[1][2], c[2][1]);
	ret += min(c[1][3], c[3][1]);
	ret += min(c[2][3], c[3][2]);
	dif += abs(c[1][2] - c[2][1]);
	dif += abs(c[1][3] - c[3][1]);
	dif += abs(c[2][3] - c[3][2]);

	printf("%d\n", ret + dif / 3 * 2);

	return 0;
}


