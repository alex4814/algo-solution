#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 105
#define MAXM 105

int n, m, s, sum;
int w[MAXN];
vector<int> g[MAXN];
vector<int>::iterator it;
deque<int> path;

void print() {
	for (int i = 0; i < (int)path.size(); ++i) {
		if (i) putchar(' ');
		printf("%d", w[ path[i] ]);
	}
	puts("");
}

void dfs(int ix) {
	if (sum == s && g[ path.back() ].size() == 0) {
		print();
		return;
	}
	for (int i = 0; i < (int)g[ix].size(); ++i) {
		path.push_back(g[ix][i]);
		sum += w[g[ix][i]];
		dfs(g[ix][i]);
		sum -= w[g[ix][i]];
		path.pop_back();
	}
}

bool greater_weight(int a, int b) {
	return w[a] > w[b];	
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w[i]);
	}
	for (int i = 0, u, k; i < m; ++i) {
		scanf("%d%d", &u, &k);
		for (int j = 0, v; j < k; ++j) {
			scanf("%d", &v);
			g[u].push_back(v);
		}
	}
	for (int i = 0; i < MAXN; ++i) {
		sort(g[i].begin(), g[i].end(), greater_weight);
	}

	path.push_back(0);
	sum = w[0];
	dfs(0);
	return 0;
}
