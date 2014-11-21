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
int v[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int r = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i]) continue;
		int cnt = 0;
	  int	x = i;
		while (!v[x]) {
			v[x] = true;
			x = a[x];
			cnt += 1;
		}
		if (cnt > 1) {
			r += cnt + (i ? 1 : -1);
		}
	}
	printf("%d\n", r);
	return 0;
}


