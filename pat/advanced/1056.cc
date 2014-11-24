#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 1005
#define MAXM 105

int np, ng;
int w[MAXN], rk[MAXN];
vector<int> q;

int main() {
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; ++i) {
		scanf("%d", &w[i]);
	}
	for (int i = 0, o; i < np; ++i) {
		scanf("%d", &o);
		q.push_back(o);
	}
	while (!q.empty()) {
		int n = q.size();
		if (n == 1) {
			rk[ q[0] ] = 1;
			break;
		}
		int g = (n + ng - 1) / ng;
		for (int i = 0; i < g; ++i) {
			int fattest = -1;
			for (int j = i * ng; j < min((i + 1) * ng, n); ++j) {
				if (w[ q[j] ] > fattest) {
					fattest = w[ q[j] ];
				}
			}
			for (int j = i * ng; j < min((i + 1) * ng, n); ++j) {
				if (w[ q[j] ] != fattest) {
					rk[ q[j] ] = g + 1;
				} else {
					q.push_back( q[j] );
				}
			}
		}
		q.erase(q.begin(), q.begin() + n);
	}
	for (int i = 0; i < np - 1; ++i) {
		printf("%d ", rk[i]);
	}
	printf("%d\n", rk[np - 1]);
	return 0;
}
