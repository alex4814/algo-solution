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
#define MAXN 105
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int n;
char g[MAXN][MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", g[i]);
	}

	double ret = 0;
	for (int I = 0; I < n; ++I) {
		for (int J = 0; J < n; ++J) { // one point
			if (g[I][J] != 'J') continue;
			
			int e;
			// right
			for (int j = J + 2; j < n; j += 2) {
				if (g[I][j] != 'J') continue;
				e = (j - J) / 2;
				int j2 = (j + J) / 2;
				int i1 = I - e, i2 = I + e;
				if (i1 >= 0 && i2 < n) {
					if (g[i1][j2] == 'B' || g[i2][j2] == 'B') continue;
					if (g[i1][j2] == '*' && g[i2][j2] == '*') continue;
					ret = max(ret, (j - J + 1) * (j - J + 1) / 2.0);
				}
			}

			// down
			for (int i = I + 2; i < n; i += 2) {
				if (g[i][J] != 'J') continue;
				e = (i - I) / 2;
				int i2 = (i + I) / 2;
				int j1 = J - e, j2 = J + e;
				if (j1 >= 0 && j2 < n) {
					if (g[i2][j1] == 'B' || g[i2][j2] == 'B') continue;
					if (g[i2][j1] == '*' && g[i2][j2] == '*') continue;
					ret = max(ret, (i - I + 1) * (i - I + 1) / 2.0);
				}
			}

			// diag
			for (int k = 1; I + k < n; ++k) {
				int i = I + k;
				int j = J + k;
				if (g[i][j] != 'J') continue;
				if (g[i][J] == 'B' || g[I][j] == 'B') continue;
				if (g[i][J] == '*' && g[I][j] == '*') continue;
				ret = max(ret, (i - I + 1) * (i - I + 1));
			}
		
		}
	}

	printf("%d\")
	return 0;
}


