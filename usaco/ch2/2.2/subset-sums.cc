/*
ID: alex4814
LANG: C++
TASK: subset
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
#define MAXN 40
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n, s;
unsigned f[MAXN][MAXN * MAXN];

/*
int dfs(int num, int curs) {
	if (curs > s / 2) return 0;
	if (curs == s / 2) return 1;

	int cnt = 0;
	for (int i = num + 1; i <= n; ++i) {
		cnt += dfs(i, curs + i);
	}
	return cnt;
}
*/

int main() {
#ifdef FILEIO
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
#endif

	scanf("%d", &n);

	/*
	// Method 1 
	s = n * (n + 1) / 2;
	if (s & 1) {
		printf("0\n");
	} else {
		printf("%d\n", dfs(0, 0) / 2);
	}
	*/

	// Method 2
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = 1;
		s = i * (i + 1) / 2;
		for (int p = 1; p <= s; ++p) {
			f[i][p] = f[i - 1][p];
			if (p - i >= 0) f[i][p] += f[i - 1][p - i];
		}
	}
	s & 1 ? printf("0\n") : printf("%u\n", f[n][s / 2] / 2);

	return 0;
}


