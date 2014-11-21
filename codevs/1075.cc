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

int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
	}
	return 0;
}


