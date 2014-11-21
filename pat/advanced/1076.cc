#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 1005
#define MAXF 105
#define MAXL 6

typedef pair<int, int> pii;
typedef long long ll;

vector<int> f[MAXN];
bool fw[MAXN];

void bfs(int s, int lvl) {
	deque<pii> q;
	q.push_back(make_pair(s, 0));
	fw[s] = true;
	while (!q.empty()) {
		pii item = q.front(); 
		q.pop_front();
		int x = item.first;
		int y = item.second;
		if (y == lvl) break;
		int sz = f[x].size();
		for (int i = 0; i < sz; ++i) {
			if (!fw[ f[x][i] ]) {
				q.push_back(make_pair(f[x][i], y + 1));
				fw[ f[x][i] ] = true;
			}
		}
	}
}

int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = 0, m; i < n; ++i) {
		scanf("%d", &m);
		for (int k = 0, x; k < m; ++k) {
			scanf("%d", &x);
			f[x - 1].push_back(i);
		}
	}
	int k;
	scanf("%d", &k);
	for (int i = 0, q; i < k; ++i) {
		scanf("%d", &q);
		fill(fw, fw + n, false);
		bfs(q - 1, l);
		int r = 0;
		for (int j = 0; j < n; ++j) {
			r += fw[j];
		}
		printf("%d\n", r - 1);
	}
	return 0;
}


