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
#define MAXN 50
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int n, m, k;
vector<int> s[MAXN];
vector<int>::iterator it;
double r[MAXN][MAXN];

void sort_and_unique(vector<int> &ans) {
	sort(ans.begin(), ans.end());
	it = unique(ans.begin(), ans.end());
	ans.resize(distance(ans.begin(), it));
}

double similarity(int i, int j) {
	vector<int> ans;
	ans.insert(ans.begin(), s[i].begin(), s[i].end());
	ans.insert(ans.begin(), s[j].begin(), s[j].end());
	sort_and_unique(ans);
	int c = s[i].size() + s[j].size() - ans.size();
	return 100.0 * c / ans.size();
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		for (int j = 0, v; j < m; ++j) {
			scanf("%d", &v);
			s[i].push_back(v);
		}
		sort_and_unique(s[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			r[i][j] = r[j][i] = similarity(i, j);
		}
	}
	scanf("%d", &k);
	for (int i = 0, a, b; i < k; ++i) {
		scanf("%d %d", &a, &b);
		printf("%.1f%%\n", r[--a][--b]);
	}

	return 0;
}


