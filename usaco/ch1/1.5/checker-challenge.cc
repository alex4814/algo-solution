/*
ID: alex4814
PROG: checker
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

#define MAXN 15
#define EPS 1e-8
#define INF 0x3f3f3f3f

int g[MAXN][MAXN];
int vcol, vdiag[2];
int s[MAXN], k, print = 3;
int n;
int ret;

inline bool valid(int r, int c) {
	return (r >= 0 && r < n) && (c >= 0 && c < n);
}

inline bool collide(int r, int c) {
	return ((1 << c) & vcol) || ((1 << (r + c)) & vdiag[0]) || ((1 << (c - r + n - 1)) & vdiag[1]);
}

void dfs(int r, int c) {
	if (r == n - 1) {
		if (print-- > 0) {
			for (int i = 0; i < k; ++i) {
				printf("%d ", s[i] + 1);
			}
			printf("%d\n", c + 1);
		}
		ret++;
		return;
	}
	s[k++] = c;
	vcol |= (1 << c);
	vdiag[0] |= (1 << (r + c));
	vdiag[1] |= (1 << (c - r + n - 1));
	g[r][c] = 1;
	for (int j = 0; j < n; ++j) {
		if (!collide(r + 1, j)) {
			dfs(r + 1, j);
		}
	}
	g[r][c] = 0;
	vdiag[1] &= ~(1 << (c - r + n - 1));
	vdiag[0] &= ~(1 << (r + c));
	vcol &= ~(1 << c);
	k--;
}

int main() {
#ifdef FILEIO
	freopen("checker.in", "r", stdin);
	freopen("checker.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int j = 0; j < (n == 6 ? n : n / 2); ++j) {
		dfs(0, j);
	}
	if (n != 6) ret <<= 1;
	if (n & 1) dfs(0, n / 2);
	printf("%d\n", ret);

	return 0;
}
