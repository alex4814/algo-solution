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
#define MAXN 40005
#define MAXC 2505

typedef pair<int, int> pii;
typedef long long ll;

char sn[MAXN][5];
vector<int> clist[MAXC];

bool name_cmp(const int &a, const int &b) {
	return strcmp(sn[a], sn[b]) < 0;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0, c; i < n; ++i) {
		scanf("%s %d", sn[i], &c);
		for (int j = 0, x; j < c; ++j) {
			scanf("%d", &x);
			clist[x].push_back(i);
		}
	}
	for (int i = 1; i <= k; ++i) {
		int sz = clist[i].size();
		printf("%d %d\n", i, sz);
		if (sz == 0) {
			continue;
		}
		sort(clist[i].begin(), clist[i].end(), name_cmp);
		for (int j = 0; j < sz; ++j) {
			printf("%s\n", sn[ clist[i][j] ]);
		}
	}
	return 0;
}


