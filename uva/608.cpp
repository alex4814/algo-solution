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
#define _N 15
#define _M 105
#define PI acos(-1.0)

int even[12], light[12], heavy[12];
char l[_N], r[_N], b[_N];

void set_union(int *a, char *b) 
{
	FOR (i, 0, strlen(b)) { a[b[i] - 'A'] += 1; }
}

int main()
{
	int n; scanf("%d", &n); while (n--) {
		MEM (even, 0); MEM (light, 0); MEM (heavy, 0);
		FOR (i, 0, 3) {
			scanf("%s%s%s", l, r, b);
			if (b[0] == 'e') {
				set_union(even, l);
				set_union(even, r);
			} else if (b[0] == 'u') {
				set_union(heavy, l);
				set_union(light, r);
			} else {
				set_union(light, l);
				set_union(heavy, r);
			}
		}
		int _l[12], _h[12];
		FOR (i, 0, 12) {
			_l[i] = light[i] * (!even[i] && light[i]);
			_h[i] = heavy[i] * (!even[i] && heavy[i]);
		}
		int max_c = 0, max_n = 0, _t = 0;
		FOR (i, 0, 12) if (_l[i] > max_n) {
			max_c = i; max_n = _l[i]; _t = -1;
		}
		FOR (i, 0, 12) if (_h[i] > max_n) {
			max_c = i; max_n = _h[i]; _t = 1;
		}
		printf("%c is the counterfeit coin and it is %s.\n", max_c + 'A', _t == -1 ? "light" : "heavy");
	}
	return 0;
}
