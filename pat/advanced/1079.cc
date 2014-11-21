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
#define MAXN 100005
#define MAXE 100005

typedef pair<int, int> pii;
typedef long long ll;

int first[MAXN], nxt[MAXE];
int u[MAXE], v[MAXE];
int w[MAXN];
double p, r, ret;

void dfs(int s, int len) {
	bool leaf = true;
	for (int e = first[s]; e != -1; e = nxt[e]) {
		dfs(v[e], len + 1);
		leaf = false;
	}
	if (leaf) {
		double rp = p * pow(1 + r / 100.0, len);
		ret += rp * w[s];
	}
}

int main() {
	int n;
	scanf("%d %lf %lf", &n, &p, &r);
	memset(first, -1, sizeof(first));
	memset(nxt, -1, sizeof(nxt));
	int e = 0;
	for (int i = 0, cnt; i < n; ++i) {
		scanf("%d", &cnt);
		if (cnt == 0) {
			scanf("%d", &w[i]);
		} else {
			for (int j = 0, to; j < cnt; ++j) {
				scanf("%d", &to);
				u[e] = i, v[e] = to;
				nxt[e] = first[ u[e] ];
				first[ u[e] ] = e;
				e += 1;
			}
		}
	}
	dfs(0, 0);
	printf("%.1f\n", ret);
	return 0;
}


