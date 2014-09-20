#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct E {
	ll a_i, b_j;
	int j;
	bool operator < (const E &y) const {	// min heap
		return a_i + b_j > y.a_i + y.b_j;
	}
};

int T, m, n;
ll a[MAXN], b[MAXN];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", a + i);
		}
		sort(a, a + n);

		for (int k = 1; k < m; ++k) {
			for (int i = 0; i < n; ++i) {
				scanf("%lld", b + i);
			}
			sort(b, b + n);

			priority_queue<E> h;
			for (int i = 0; i < n; ++i) {
				h.push((E){ a[i], b[0], 0 });
			}

			for (int i = 0; i < n; ++i) {
				E e = h.top(); h.pop();
				a[i] = e.a_i + e.b_j;
				if (e.j + 1 < n) {
					h.push((E){ e.a_i, b[e.j + 1], e.j + 1 });
				}
			}
		}

		for (int i = 1; i < n; ++i) {
			printf("%lld ", a[i - 1]);
		}
		printf("%lld\n", a[n - 1]);
	}
	return 0;
}


