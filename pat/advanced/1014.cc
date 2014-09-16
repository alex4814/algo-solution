#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 1005

typedef pair<int, int> pii;
typedef long long ll;

int n, m, k, q;
int t[MAXN], ct[MAXN], wt[MAXN];
queue<int> w[20];

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < k; ++i) {
		scanf("%d", t + i);
	}

	memset(ct, -1, sizeof(ct));
	int tot = min(k, n * m);
	for (int i = 0; i < tot; ++i) {
		w[i % n].push(i);
	}
	for (int i = 0; i < 9 * 60; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!w[j].empty() && wt[j] + t[ w[j].front() ] == i) {
				wt[j] = ct[ w[j].front() ] = i;
				w[j].pop();
				if (tot < k) w[j].push(tot++);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!w[i].empty()) {
			ct[ w[i].front() ] = wt[i] + t[ w[i].front() ];
		}
	}
	for (int i = 0, c; i < q; ++i) {
		scanf("%d", &c); c--;
		if (ct[c] != -1) {
			printf("%02d:%02d\n", ct[c] / 60 + 8, ct[c] % 60);
		} else {
			printf("Sorry\n");
		}
	}
	return 0;
}


