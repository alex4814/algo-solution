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

int d[32];

bool is_palindromic(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] != a[n - 1 - i]) return false;
	}
	return true;
}

int main() {
	int n, b;
	scanf("%d %d", &n, &b);
	if (n == 0) {
		printf("Yes\n0\n");
		return 0;
	}
	int nd = 0;
	while (n > 0) {
		d[nd++] = n % b;
		n /= b;
	}
	puts(is_palindromic(d, nd) ? "Yes" : "No");
	printf("%d", d[nd - 1]);
	for (int i = nd - 2; i >= 0; --i) {
		printf(" %d", d[i]);
	}
	putchar('\n');
	return 0;
}


