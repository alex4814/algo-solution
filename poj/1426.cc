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
#define MAXN 205
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int n;
int r[MAXN];

int main() {
	int x, m, z, o;

	while (scanf("%d", &n), n) {
		memset(r, 0, sizeof(r));
		for (x = 1, m = 1; ; ++m, x = x * 10 + 1) {
			x = x % n;
			if (x == 0) {
				o = m, z = 0;
				break;
			} else if (r[x] != 0) {
				o = m - r[x], z = r[x];
				break;
			}
			r[x] = m;
		}
		printf("%d %d ", n, o + z);
		for (int i = 0; i < o; ++i) putchar('1');
		for (int i = 0; i < z; ++i) putchar('0');
		putchar('\n');
	}
	return 0;
}


