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
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int c[MAXN];
int p[MAXN];

int main() {
	int nc;
	scanf("%d", &nc);
	for (int i = 0; i < nc; ++i) {
		scanf("%d", c + i);
	}
	int np;
	scanf("%d", &np);
	for (int i = 0; i < np; ++i) {
		scanf("%d", p + i);
	}
	sort(c, c + nc);
	sort(p, p + np);
	int i, j;
	ll r = 0;
	i = 0;
	j = 0;
	while (i < nc && j < np) {
		if (c[i] < 0 && p[j] < 0) {
			r += (ll)c[i] * p[j];
		} else {
			break;
		}
		i += 1;
	 	j += 1;
	}
	i = nc - 1;
	j = np - 1;
	while (i >= 0 && j >= 0) {
		if (c[i] > 0 && p[j] > 0) {
			r += (ll)c[i] * p[j];
		} else {
			break;
		}
		i -= 1;
		j -= 1;
	}
	printf("%lld\n", r);
	return 0;
}


