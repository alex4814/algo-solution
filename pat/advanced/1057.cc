#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int c[MAXN];

int lowbit(int x) {
	return x & -x;
}

int sum(int n) {
	int r = 0;
	while (n > 0) {
		r += c[n];
		n -= lowbit(n);
	}
	return r;
}

void modify_by_one(int x, int one) {
	while (x < MAXN) {
		c[x] += one;
		x += lowbit(x);
	}
}

int median(int x) {
	int l = 1, r = MAXN;
	while (l < r) {
		int m = l + (r - l) / 2;
		sum(m) >= x ? r = m : l = m + 1;
	}
	return l;
}

vector<int> stack;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i) {
		char op[20];
		scanf("%s", op);
		if (op[1] == 'u') {
			scanf("%d", &x);
			modify_by_one(x, 1);
			stack.push_back(x);
		} else {
			if (stack.empty()) {
				printf("Invalid\n");
			} else if (op[1] == 'o') {
				x = stack.back();
				stack.pop_back();
				modify_by_one(x, -1);
				printf("%d\n", x);
			} else {
				x = stack.size();
				printf("%d\n", median((x + 1) / 2));
			}
		}
	}
	return 0;
}
