#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 180005
#define MAXM 105

int n, k;
set<int> c[MAXN];

inline int convert(char *s) {
	int ret = 0;
	for (int i = 3; i >= 0; --i) {
		ret = ret * 26 + (i == 3 ? s[i] - '0' : s[i] - 'A');
	}
	return ret;
}

int main() {
	char name[5];

	scanf("%d%d", &n, &k);
	for (int i = 0, id, cn; i < k; ++i) {
		scanf("%d%d", &id, &cn);
		for (int j = 0; j < cn; ++j) {
			scanf("%s", name);
			c[ convert(name) ].insert(id);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", name);
		int id = convert(name);
		printf("%s %d", name, (int)c[id].size());
		for (set<int>::iterator it = c[id].begin(); it != c[id].end(); ++it) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}
