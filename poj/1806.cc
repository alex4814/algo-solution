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

int n, u;
int g[19][19][19];

void gao() {
	int k = 2 * u + 1;
	for (int l = 0; l < k; ++l) {
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < k; ++j) {
				g[l][i][j] = abs(l - u) + abs(i - u) + abs(j - u);
			}
		}
	}
}

void print() {
	if (u == 0) {
		printf("slice #1:\n0\n");
		return;
	}

	int k = 2 * u + 1;
	memset(g, 0, sizeof(g));
	gao();

	for (int l = 0; l < k; ++l) {
		printf("slice #%d:\n", l + 1);
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < k; ++j) {
				putchar(g[l][i][j] > u ? '.' : g[l][i][j] + '0');
			}
			putchar('\n');
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int nCase = 1; nCase <= n; ++nCase) {
		scanf("%d", &u);
		printf("Scenario #%d:\n", nCase);
		print();
		putchar('\n');
	}
	return 0;
}


