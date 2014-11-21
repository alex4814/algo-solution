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
#define MAXN 105
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	int r1 = INT_MIN;
	int r2 = INT_MAX;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		r1 = max(r1, a[i]);
		r2 = min(r2, a[i]);
	}
	printf("%d %d\n", r2, r1);
	return 0;
}


