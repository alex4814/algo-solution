#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)

typedef long long ll;
int n, nc, np;
vector<int> c[2], p[2];

bool gt(int a, int b) { return a > b; }

int main() {
	while (scanf("%d", &nc), nc >= 0) {
		c[0].clear(), c[1].clear();
		p[0].clear(), p[1].clear();

		FOR (i, 0, nc) { 
			scanf("%d", &n);
			n > 0 ? c[0].push_back(n), 0 : 0;
			n < 0 ? c[1].push_back(n), 0 : 0;
		}
		scanf("%d", &np);
		FOR (i, 0, np) { 
			scanf("%d", &n);
			n > 0 ? p[0].push_back(n), 0 : 0;
			n < 0 ? p[1].push_back(n), 0 : 0;
		}

		sort(c[0].begin(), c[0].end(), gt);
		sort(c[1].begin(), c[1].end());
		sort(p[0].begin(), p[0].end(), gt);
		sort(p[1].begin(), p[1].end());
		ll ret = 0;

		n = min(c[0].size(), p[0].size());
		for (int i = 0; i < n; ++i) {
			ret += (ll)c[0][i] * p[0][i];
		}
		n = min(c[1].size(), p[1].size());
		for (int i = 0; i < n; ++i) {
			ret += (ll)c[1][i] * p[1][i];
		}
		printf("%I64d\n", ret);
	}
	return 0;
}
