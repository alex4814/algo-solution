/*
ID: alex4814
LANG: C++
TASK: zerosum
*/

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
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int n;
int ops[10];
char o[] = " +-";

void print() {
	putchar('1');
	for (int i = 2; i <= n; ++i) {
		putchar(o[ ops[i] ]);
		putchar(i + '0');
	}
	putchar('\n');
}

int cal_sum(int sum, int num, int w, int cur) {
	//printf("sum = %d, num = %d, w = %d, cur = %d\n", sum, num, w, cur);
	if (cur == 1) {
		return sum + w + num;
	}
	if (ops[cur] == 0) {
		return cal_sum(sum, cur * w + num, w * 10, cur - 1);
	} else if (ops[cur] == 1) {
		return cal_sum(sum + cur * w + num, 0, 1, cur - 1);
	} else {
		return cal_sum(sum - (cur * w + num), 0, 1, cur - 1);
	}
}

void dfs(int s, int cur) {
	ops[cur] = s;
	if (cur == n) {
		//print();
		//fprintf(stderr, "\tsum = %d\n", cal_sum(0, 0, 1, n));
		if (cal_sum(0, 0, 1, n) == 0) print();
		return;
	}
	dfs(0, cur + 1);
	dfs(1, cur + 1);
	dfs(2, cur + 1);
}

int main() {
#ifdef FILEIO
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
#endif
	scanf("%d", &n);
	dfs(1, 1);
	return 0;
}


