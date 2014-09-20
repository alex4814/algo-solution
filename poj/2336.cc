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
#define MAXN 2005
#define MAXE 1005
#define INF 0x3f3f3f3f

typedef pair<int, int> pii;
typedef long long ll;

int T, n, t, m;
int a[MAXN];
int ft[MAXN], fc[MAXN];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &t, &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d", a + i);
		}

		ft[0] = fc[0] = 0;
		vector<pii> p;
		for (int i = 1; i <= m; ++i) {
			p.clear();
			for (int j = i - 1; j >= 0 && j >= i - n; --j) {
				int arr = max(a[i], ft[j] + (j ? (t << 1) : 0));
				p.push_back(make_pair(arr, j));
			}
			sort(p.begin(), p.end());
			ft[i] = p[0].first;
			int cnt = fc[ p[0].second ];
			for (int k = 1; k < (int)p.size(); ++k) {
				if (p[k].first == p[k - 1].first) {
					cnt = min(cnt, fc[ p[k].second ]);
				}
			}
			fc[i] = cnt + 1;
		}
		printf("%d %d\n", ft[m] + t, fc[m]);
	}
	return 0;
}


