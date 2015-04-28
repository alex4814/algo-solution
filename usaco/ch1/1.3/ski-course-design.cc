/*
ID: alex4814
LANG: C++
TASK: skidesign
*/

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

#define FILEIO

int n;
int h[MAXN];

int cost(int d1, int d2) {
	int left = h[0] + d1;
	int right = h[n - 1] - d2;
	int low = lower_bound(h, h + n, left) - h;
	int high = upper_bound(h, h + n, right) - h;
	int sum = 0;
	for (int i = 0; i < low; ++i) {
		int x = abs(left - h[i]);
		sum += x * x;
	}
	for (int i = high; i < n; ++i) {
		int x = abs(right - h[i]);
		sum += x * x;
	}
	return sum;
}

int main() {
#ifdef FILEIO
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", h + i);
	}
	sort(h, h + n);
	int diff = h[n - 1] - h[0] - 17;
	if (diff <= 0) {
		printf("0\n");
	} else {
		int r = INT_MAX;
		for (int i = 0; i < diff; ++i) {
			r = min(r, cost(i, diff - i));
		}
		printf("%d\n", r);
	}
	return 0;
}


