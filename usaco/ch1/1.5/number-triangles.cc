/*
ID: alex4814
PROG: numtri
LANG: C++
*/

#define NDEBUG
#define FILEIO

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 1005
#define EPS 1e-8
#define INF 0x3f3f3f3f

int n;
int d[MAXN][MAXN];
int f[MAXN][MAXN];

int main() {
#ifdef FILEIO
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			scanf("%d", &d[i][j]);
		}
	}

	f[1][1] = d[1][1];
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + d[i][j];
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret = max(ret, f[n][i]);
	}
	printf("%d\n", ret);

	return 0;
}
