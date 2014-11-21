/*
ID: alex4814
LANG: C++
TASK: combo
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
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int a[3], b[3];

int inter(int x, int y, int n) {
	int r = 0;
	for (int i = -2; i <= 2; ++i) {
		for (int j = -2; j <= 2; ++j) {
			if ((x + i + n) % n == (y + j + n) % n) {
				++r;
			}
		}
	}
	return r;
}	

int main() {
#ifdef FILEIO
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) {
		scanf("%d", a + i); a[i]--;
	}
	for (int i = 0; i < 3; ++i) {
		scanf("%d", b + i); b[i]--;
	}
	int r = 1;
	for (int i = 0; i < 3; ++i) {
		r *= inter(a[i], b[i], n);
	}
	if (n < 5) {
		printf("%d\n", n * n * n);
	} else {
		printf("%d\n", 250 - r);
	}
	return 0;
}


