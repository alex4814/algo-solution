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
#define MAXN 100000
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int s1, s2, n;
int list[MAXN];
vector<int> l1, l2;

int main() {
	char d[10];

	scanf("%d %d %d", &s1, &s2, &n);
	for (int i = 0, u, v; i < n; ++i) {
		scanf("%d %s %d", &u, d, &v);
		list[u] = v;
	}

	while (s1 != -1) {
		l1.push_back(s1);
		s1 = list[s1];
	}
	while (s2 != -1) {
		l2.push_back(s2);
		s2 = list[s2];
	}
	int ret = -1;
	while (!l1.empty() && !l2.empty()) {
		int u = l1.back(); l1.pop_back();
		int v = l2.back(); l2.pop_back();
		if (u == v) {
			ret = u;
		}
	}
	if (ret == -1) {
		printf("-1\n");
	} else {
		printf("%05d\n", ret);
	}

	return 0;
}


