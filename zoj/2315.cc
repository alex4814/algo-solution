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
#define MAXN 500005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int T, n;
int p[MAXN];

struct Node {
	int id;
	int lvl;
	bool operator < (const Node &b) const {
		return lvl > b.lvl;
	}
};

Node a[MAXN];
bool m[MAXN], s[MAXN];
vector<int> q;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		for (int i = 2; i <= n; ++i) {
			scanf("%d", p + i);
			a[i].id = i, a[i].lvl = a[ p[i] ].lvl + 1;
			m[i] = s[i] = 0;
		}
		a[1].id = m[1] = 1, s[1] = 0;

		q.clear();
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; ++i) {
			if (m[ a[i].id ] == 1 || s[ p[ a[i].id ] ] == 1) continue;
			s[ p[ a[i].id ] ] = m[ p[ a[i].id ] ] = 1;
		   	q.push_back(a[i].id);
		}

		printf("%d\n", q.size() * 1000);
		sort(q.begin(), q.end());
		for (int i = 0; i < q.size(); ++i) {
			printf("%d%c", q[i], i + 1 == q.size() ? '\n' : ' ');
		}
		putchar('\n');
	}

	return 0;
}


