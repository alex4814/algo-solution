/*
ID: alex4814
PROG: milk3
LANG: C++
*/

#define NDEBUG
#define FILEIO

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 21
#define EPS 1e-8
#define INF 0x3f3f3f3f

struct State {
	int a, b, c;
};

int A, B, C;
int a, b, c;
bool vis[MAXN][MAXN][MAXN];
int ret[MAXN], k;

queue<State> q;

void bfs(State s) {
	vis[s.a][s.b][s.c] = true;
	q.push(s);

	State v;
	while (!q.empty()) {
		State u = q.front();
		//printf("%d %d %d\n", u.a, u.b, u.c);
		if (u.a == 0) {
			ret[k++] = u.c;
		}

		// a to b
		a = u.a + u.b - B;
		b = u.a + u.b;
		v = (State){ (a < 0 ? 0 : a), (b > B ? B : b), u.c };
		if (!vis[v.a][v.b][v.c]) q.push(v), vis[v.a][v.b][v.c] = true;

		// b to a
		a = u.b + u.a;
		b = u.b + u.a - A;
		v = (State){ (a > A ? A : a), (b < 0 ? 0 : b), u.c };
		if (!vis[v.a][v.b][v.c]) q.push(v), vis[v.a][v.b][v.c] = true;

		// a to c
		a = u.a + u.c - C;
		c = u.a + u.c;
		v = (State){ (a < 0 ? 0 : a), u.b, (c > C ? C : c) };
		if (!vis[v.a][v.b][v.c]) q.push(v), vis[v.a][v.b][v.c] = true;

		// c to a
		a = u.a + u.c;
		c = u.a + u.c - A;
		v = (State){ (a > A ? A : a), u.b, (c < 0 ? 0 : c) };
		if (!vis[v.a][v.b][v.c]) q.push(v), vis[v.a][v.b][v.c] = true;

		// b to c
		b = u.b + u.c - C;
		c = u.b + u.c;
		v = (State){ u.a, (b < 0 ? 0 : b), (c > C ? C : c) };
		if (!vis[v.a][v.b][v.c]) q.push(v), vis[v.a][v.b][v.c] = true;

		// c to b
		b = u.b + u.c;
		c = u.b + u.c - B;
		v = (State){ u.a, (b > B ? B : b), (c < 0 ? 0 : c) };
		if (!vis[v.a][v.b][v.c]) q.push(v), vis[v.a][v.b][v.c] = true;

		q.pop();
	}
}

int main() {
#ifdef FILEIO
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
#endif

	scanf("%d %d %d", &A, &B, &C);
	bfs((State){ 0, 0, C });

	sort(ret, ret + k);
	for (int i = 0; i < k; ++i) {
		printf("%d%c", ret[i], i + 1 == k ? '\n' : ' ');
	}

	return 0;
}
