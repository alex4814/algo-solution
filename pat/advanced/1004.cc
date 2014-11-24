#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 105
#define MAXM 105
#define mp make_pair

typedef pair<int, int> pii;
int n, m, k, cur_lv, cnt;
int g[MAXN][MAXN];

queue<pii> q;
vector<int> ret;

void bfs(int s) {
	while (!q.empty()) {
		pii u = q.front();
		if (u.second != cur_lv) {
			ret.push_back(cnt);
			++cur_lv;
			cnt = 0;
		}
		bool found = false;
		for (int i = 1; i <= n; ++i) {
			if (g[u.first][i]) { 
				q.push(mp(i, cur_lv + 1));
				found = true;
			}
		}
		cnt += found ? 0 : 1;
		q.pop();
	}
	ret.push_back(cnt);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, s, t; i < m; ++i) {
		scanf("%d%d", &s, &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &t);
			g[s][t] = 1;
		}
	}

	q.push(mp(1, cur_lv = 0));
	bfs(1);
	
	for (int i = 0; i < ret.size() - 1; ++i) {
		printf("%d ", ret[i]);
	}
	printf("%d\n", ret[ret.size() - 1]);
	return 0;
}
