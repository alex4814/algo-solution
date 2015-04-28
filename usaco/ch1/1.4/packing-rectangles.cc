/*
ID: alex4814
PROG: packrec
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

#define MAXN 100005
#define EPS 1e-8
#define INF 0x3f3f3f3f

struct Rectangle {
	int x, y;
	bool operator < (const Rectangle &b) const {
		return x * y < b.x * b.y || (x * y == b.x * b.y && x < b.x);
	}
	Rectangle rotate() {
		return (Rectangle){ y, x };
	}
};

Rectangle r[4], _r[4];
bool vis[4];
vector<Rectangle> ret;

// 0 for up, 1 for down, 2 for left, 3 for right
Rectangle pack(Rectangle a, Rectangle b, int dir) {
	Rectangle ret;
	if (dir == 0 || dir == 1) {
		ret = (Rectangle){ max(a.x, b.x), a.y + b.y };
	} else {
		ret = (Rectangle){ a.x + b.x, max(a.y, b.y) };
	}
	return ret;
}

void dfs(Rectangle rec, int ix, int depth) {
	if (depth == 3) {
		ret.push_back(rec);
		return;
	}
	vis[ix] = true;
	for (int i = 0; i < 4; ++i) {
		if (vis[i]) continue;
		for (int d = 0; d < 4; ++d) {
			dfs(pack(rec, r[i], d), i, depth + 1);
			dfs(pack(rec, _r[i], d), i, depth + 1);
		}
	}
	vis[ix] = false;
}

void dfs(int *p, int ix) {
	static vector<Rectangle> f;
	if (ix == 4) {
		int x1 = max(f[0].x, f[2].x) + max(f[1].x, f[3].x);
		int y1 = max(f[0].y + f[2].y, f[1].y + f[3].y);
		ret.push_back((Rectangle){ x1, y1 });

		int x2 = max(f[0].x + f[1].x, f[2].x + f[3].x);
		int y2 = max(f[0].y, f[1].y) + max(f[2].y, f[3].y);
		ret.push_back((Rectangle){ x2, y2 });

		if ((f[0].x > f[2].x && f[2].y > f[3].y && f[3].x > f[1].x && f[1].y > f[0].y) ||
			(f[0].y > f[2].y && f[2].x > f[3].x && f[3].y > f[1].y && f[1].x > f[0].x)) {
			ret.push_back((Rectangle){ x2, y1 });
		}
		return;
	}

	f.push_back(r[ p[ix] ]);
	dfs(p, ix + 1);
	f.pop_back();

	f.push_back(_r[ p[ix] ]);
	dfs(p, ix + 1);
	f.pop_back();
}

int main() {
#ifdef FILEIO
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);
#endif

	for (int i = 0; i < 4; ++i) {
		scanf("%d %d", &r[i].x, &r[i].y);
		_r[i] = r[i].rotate();
	}

	for (int i = 0; i < 4; ++i) {
		dfs(r[i], i, 0);
		dfs(_r[i], i, 0);
	}
	int p[4] = { 0, 1, 2, 3 };
	do {
		dfs(p, 0);
	} while (next_permutation(p, p + 4));

	sort(ret.begin(), ret.end());

	int sz = ret.size(), k = 1;
	for (int i = 1; i < sz; ++i) {
		if (ret[i].x * ret[i].y != ret[0].x * ret[0].y) break;
		if (ret[i].x == ret[i - 1].x && ret[i].y == ret[i - 1].y) continue;
		if (ret[i].x > ret[i].y) break;
		ret[k++] = ret[i];
	}

	printf("%d\n", ret[0].x * ret[0].y);
	for (int i = 0; i < k; ++i) {
		printf("%d %d\n", ret[i].x, ret[i].y);
	}

	return 0;
}
