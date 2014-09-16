#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 1005
#define MAXM 105

struct Node {
	int ch[2];
	int key;
}node[MAXN];

int n, rt, cnt;
int a[MAXN];

bool build(int l, int r, int f) {
	if (l == r - 1) {
		node[cnt].key = a[l];
		node[cnt].ch[0] = node[cnt].ch[1] = -1;
		cnt++;
		return true;
	}
	int m;
	for (m = l + 1; i < r; ++i) {
		if (!f && a[m] >= a[l]) break;
		if (f && a[m] < a[l]) break;
	}
	for (int i = l + 1; i < m; ++i) {
		if (!f && a[i] >= a[l]) return false;
		if (f && a[i] < a[l]) return false;
	}
	
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	if ((cnt = 0, build(rt, 0, n, 0)) || (cnt = 0, build(rt, 0, n, 1))) {
		puts("YES");
		postorder(rt);
	} else {
		puts("NO");
	}

	return 0;
}
