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

typedef pair<int, int> pii;
typedef long long ll;

int s[MAXN];
pii p[MAXN];

int main() {
	int n, k;
	while (scanf("%d", &n) == 1) {
		for (int i = 1, a; i <= n; ++i) {
			scanf("%d", &a);
			s[i] = s[i - 1] + a;
			p[i - 1] = make_pair(s[i], i);
		}
		sort(p, p + n);
		scanf("%d", &k);
		bool found = false;
		int start, end;
		for (int i = 0; !found && i < n; ++i) {
			int ns = s[i] + k;
			int lb = lower_bound(p, p + n, make_pair(ns, 0)) - p;
			int ub = upper_bound(p, p + n, make_pair(ns, n)) - p;
			for (int j = lb; j < ub; ++j) {
				if (p[j].first == ns && p[j].second > i) {
					found = true;
					start = i + 1;
					end = p[j].second;
					break;
				}
			}
		}
		if (found) {
			printf("%d %d\n", start, end);
		} else {
			puts("No");
		}
	}
	return 0;
}


