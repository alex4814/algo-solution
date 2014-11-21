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
#define MAXN 35
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int a[MAXN], b[MAXN];
int bt[MAXN << 10];

void build(int pl, int pr, int il, int ir, int rt) {
	if (pl > pr || il > ir) return;
	//printf("post l = %d, post r = %d\n", pl, pr);
	//printf("in l = %d, in r = %d\n", il, ir);
	bt[rt] = a[pr];
	//printf("(%d) = %d\n\n", rt, bt[rt]);
	if (pl == pr || il == ir) return;
	int r_idx = -1;
	for (int i = il; i <= ir; ++i) {
		if (b[i] == bt[rt]) {
			r_idx = i;
			break;
		}
	}
	int n_lch = r_idx - il;
	build(pl, pl + n_lch - 1, il, r_idx - 1, rt << 1);
	build(pl + n_lch, pr - 1, r_idx + 1, ir, rt << 1 | 1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
	}
	memset(bt, -1, sizeof(bt));
	build(0, n - 1, 0, n - 1, 1);
	int cnt = 0;
	for (int i = 0; i < MAXN << 10; ++i) {
		if (bt[i] != -1) {
			if (cnt++) putchar(' ');
			printf("%d", bt[i]);
		}
	}
	putchar('\n');
	return 0;
}


