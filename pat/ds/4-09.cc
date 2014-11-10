#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 1005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	int lkey, rkey;
	int lch, rch;
};

bool checked[MAXN];
Node node[MAXN];

int max_lkey(int rt) {
	if (rt == -1) return INT_MIN;
	int ret = node[rt].lkey;
	ret = max(ret, max_lkey(node[rt].lch));
	ret = max(ret, max_lkey(node[rt].rch));
	return ret;
}

int min_lkey(int rt) {
	if (rt == -1) return INT_MAX;
	int ret = node[rt].lkey;
	ret = min(ret, min_lkey(node[rt].lch));
	ret = min(ret, min_lkey(node[rt].rch));
	return ret;
}

bool is_cartesian(int ix) {
	if (checked[ix]) return true;
	checked[ix] = true;
	int lch = node[ix].lch;
	int rch = node[ix].rch;
	bool ret = true;
	if (lch != -1) {
		if (max_lkey(lch) > node[ix].lkey) return false;
		if (node[lch].rkey < node[ix].rkey) return false;
		ret &= is_cartesian(lch);
	}
	if (rch != -1) {
		if (min_lkey(rch) < node[ix].lkey) return false;
		if (node[rch].rkey < node[ix].rkey) return false;
		ret &= is_cartesian(rch);
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &node[i].lkey);
		scanf("%d", &node[i].rkey);
		scanf("%d", &node[i].lch);
		scanf("%d", &node[i].rch);
	}
	for (int i = 0; i < n; ++i) {
		if (!checked[i]) {
			if (!is_cartesian(i)) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	return 0;
}


