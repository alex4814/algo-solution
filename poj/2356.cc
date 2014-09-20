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
#define MAXN 10005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int a[MAXN], n;
int s[MAXN], r[MAXN];

int main() {
	int b, e;

	while (scanf("%d", &n) == 1) {
		bool found = false;
		memset(r, -1, sizeof(r));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			if (found) continue;
			s[i] = s[i - 1] + a[i];
			int rm = s[i] % n;
			if (rm == 0) {
				b = 1, e = i;
				found = true;
			} else if (r[rm] != -1) {
				b = r[rm] + 1, e = i;
				found = true;
			}
			r[rm] = i;
		}
		printf("%d\n", e - b + 1);
		for (int i = b; i <= e; ++i) {
			printf("%d\n", a[i]);
		}
	}
	return 0;
}


