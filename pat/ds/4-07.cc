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
#define INF 0x3f3f3f3f

typedef pair<int, int> pii;
typedef long long ll;

int a[MAXN];

void heapify(int *a, int n, int i) {
	int l = 2 * i, r = l + 1;
	int ix = (l <= n && a[l] < a[i]) ? l : i;
	if (r <= n && a[r] < a[ix]) ix = r;
	if (ix != i) {
		swap(a[i], a[ix]);
		heapify(a, n, ix);
	}
}

void build_heap(int *a, int n) {
	for (int i = n / 2; i >= 1; --i) {
		heapify(a, n, i);
	}
}

int heap_extract(int *a, int n) {
	if (n < 1) return -1;
	int ret = a[1];
	a[1] = a[n--];
	heapify(a, n, 1);
	return ret;
}

void heap_increase_key(int *a, int i, int key) {
	if (key < a[i]) return;
	a[i] = key;
	while (i > 1 && a[i / 2] > a[i]) {
		swap(a[i], a[i / 2]);
		i >>= 1;
	}
}

void heap_insert(int *a, int n, int key) {
	a[++n] = -INF;
	heap_increase_key(a, n, key);
}

// Haffman Tree
int main() {
	int n, m = 0;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		heap_insert(a, m++, x);
	}
	int ret = 0;
	for (int i = 1; i < m; ++i) {
		int x = heap_extract(a, n--);
		int y = heap_extract(a, n--);
		//printf("%d %d\n", x, y);
		heap_insert(a, n++, x + y);
		ret += x + y;
	}
	printf("%d\n", ret);
	return 0;
}


