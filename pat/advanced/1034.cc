#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 2005
#define MAXE 1005

typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef long long ll;

map<string, int> id;
int g[MAXN][MAXN];
int val[MAXN], cid[MAXN];
bool vis[MAXN];
int t, tot;

void dfs(int k, int n, int cp) {
	vis[k] = true;
	cid[k] = cp;
	for (int i = 0; i < n; ++i) {
		if (!vis[i] && g[k][i]) {
			dfs(i, n, cp);
		}
	}
}

vector<string> names;
vector<int> gang[MAXN];
vector<psi> ret;

int main() {
	int n, th;
	cin >> n >> th;
	for (int i = 0, w; i < n; ++i) {
		string a, b;
		cin >> a >> b >> w;
		if (id.count(a) == 0) {
			id[a] = t++;
			names.push_back(a);
		}
		if (id.count(b) == 0) {
			id[b] = t++;
			names.push_back(b);
		}
		int u = id[a];
	  int	v = id[b];
		g[u][v] += w;
		g[v][u] += w;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			val[i] += g[i][j];
		}
	}
	int cnt = 0;	// number of components
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i, n, cnt++);
		}
	}
	for (int i = 0; i < n; ++i) {
		gang[ cid[i] ].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int sz = gang[i].size();
		int tot = 0;
		int n_head = 0;
		int max_weight = 0;
		int head = 0;
		for (int j = 0; j < sz; ++j) {
			if (val[ gang[i][j] ] > max_weight) {
				max_weight = val[ gang[i][j] ];
				n_head = 1;
				head = gang[i][j];
			} else if (val[ gang[i][j] ] == max_weight) {
				n_head += 1;
			}
			for (int k = j + 1; k < sz; ++k) {
				tot += g[j][k];
			}
		}
		if (tot > th && n_head == 1) {
			ret.push_back(make_pair(names[head], sz));
		}
	}
	sort(ret.begin(), ret.end());
	int sz = ret.size();
	printf("%d\n", sz);
	for (int i = 0; i < sz; ++i) {
		cout << ret[i].first << " " << ret[i].second << endl;
	}
	return 0;
}


