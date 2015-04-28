#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define _N 10005
#define _M 105
#define PI acos(-1.0)

int d[10];
int n, m, _t;
int q[_N], qh, qt, parent[_N], digit[_N];

void print(int x)
{
	if (parent[x]) { print(parent[x]); }
	putchar(digit[x] + '0');
}

void bfs()
{
	qh = qt = 0;
	FOR (i, 1, 10) if (i % n == 0 && !d[i]) { printf("%d\n", i); return; }
	FOR (i, 1, 10) if (!d[i] && parent[i % n] == -1) { q[qt++] = i % n; digit[i % n] = i; parent[i % n] = 0; }
	while (qh < qt) {
		int x = q[qh++];
		FOR (i, 0, 10) if (!d[i]) { 
			_t = (x * 10 + i) % n; 
			if (_t == 0) {
				print(x); printf("%d\n", i);
				return;
			}
			if (parent[_t] == -1) {
				parent[_t] = x; digit[_t] = i; q[qt++] = _t;
			}
		}
	}
	printf("-1\n");
}

int main()
{
	int n_case = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		MEM (parent, -1);
		MEM (d, 0);
		FOR (i, 0, m) { scanf("%d", &_t); d[_t] = 1; }
		printf("Case %d: ", ++n_case);
		bfs();
	}
	return 0;
}
