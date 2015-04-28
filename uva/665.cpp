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
#define _N 105
#define _M 105
#define PI acos(-1.0)

bool even[_N], light[_N], heavy[_N];
int l[_N], r[_N];
char balance[10];
int m, n, k, _t;

void set_union(bool *a, int *b) 
{
	FOR (i, 0, _t) { a[b[i] - 1] = true; }
}

void print()
{
	FOR (i, 0, n) {
		printf("%d %d %d\n", even[i], light[i], heavy[i]);
	}
}
int main()
{
	int m; scanf("%d", &m); while (m--) {
		MEM (even, 0); MEM (light, 0); MEM (heavy, 0);
		scanf("%d%d", &n, &k);
		FOR (i, 0, k) {
			scanf("%d", &_t);
			FOR (j, 0, _t) { scanf("%d", &l[j]); }
			FOR (j, 0, _t) { scanf("%d", &r[j]); }
			scanf("%s", balance);
			if (balance[0] == '=') {
				set_union(even, l);
				set_union(even, r);
			} else if (balance[0] == '>') {
				set_union(heavy, l);
				set_union(light, r);
			} else {
				set_union(light, l);
				set_union(heavy, r);
			}
		}
		//print();
		bool _l[_N], _h[_N];
		FOR (i, 0, n) {
			_l[i] = !even[i] && light[i];
			_h[i] = !even[i] && heavy[i];
		}
		int result = -1, cnt = 0;
		FOR (i, 0, n) if (_l[i]) {
			++cnt; result = i;
		} else if (_h[i]) {
			++cnt; result = i;
		}
		cnt == 1 ? printf("%d\n", result + 1) : printf("0\n");
		printf("\n");
	}
	return 0;
}

