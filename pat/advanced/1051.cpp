#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 1005
#define MAXM 105

int m, n, k;
int seq[MAXN];

bool possible() {
	stack<int> s;
	int ix = 0;
	for (int i = 0; i < n; ++i) {
		if (s.size() < m) {
			s.push(i + 1);
		} else {
			break;
		}
		while (ix < n && !s.empty() && s.top() == seq[ix]) {
			s.pop();
			++ix;
		}
	}
	return s.size() == 0;
}

int main() {
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &seq[j]);
		}
		possible() ? puts("YES") : puts("NO");
	}
	return 0;
}
