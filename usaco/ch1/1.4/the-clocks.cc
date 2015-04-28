/*
ID: alex4814
PROG: clocks
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

#define MAXN 9
#define EPS 1e-8
#define INF 0x3f3f3f3f

struct Pair {
	int s, w, p;
};

Pair q[1 << (2 * MAXN)];
bool vis[1 << (2 * MAXN)];

char w[MAXN][10] = {
	"ABDE", "ABC", "BCEF",
	"ADG", "BDEFH", "CFI",
	"DEGH", "GHI", "EFHI",
};
int d[MAXN];

int rotate(int s, int ix) {
	int n = strlen(w[ix]), k = 0;
	for (int i = 0; i < MAXN; ++i) {
		d[i] = s % 4;
		s /= 4;
	}
	for (int i = 0; i < n; ++i) {
		(d[ MAXN - 1 - (w[ix][i] - 'A') ] += 1) %= 4;
	}
	int ret = 0;
	for (int i = MAXN - 1; i >= 0; --i) {
		ret = ret * 4 + d[i];
	}
	return ret;
}

int bfs(int s) {
	static int h = 0, t = 0;
	vis[s] = true;
	q[t++] = (Pair){ s, -1, -1 };

	while (h < t) {
		Pair u = q[h];
		if (u.s == 0) {
			return h;
		}
		for (int i = 0; i < MAXN; ++i) {
			int _s = rotate(u.s, i);
			if (!vis[_s]) {
				vis[_s] = true;
				q[t++] = (Pair){ _s, i + 1, h };
			}
		}
		++h;
	}
	return -1;
}

void print(int e) {
	if (q[e].p == 0) {
		printf("%d", q[e].w);
		return;
	}
	print(q[e].p);
	printf(" %d", q[e].w);
}

int main() {
#ifdef FILEIO
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
#endif

	int s = 0;
	for (int i = 0, n; i < MAXN; ++i) {
		scanf("%d", &n);
		s = s * 4 + (n == 12 ? 0 : n / 3);
	}

	int e = bfs(s);
	print(e);
	printf("\n");

	return 0;
}
