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
#define MAXN 10005

typedef pair<int, int> pii;
typedef long long ll;

struct Customer {
	int at, pt, dt;
	bool operator < (const Customer &b) const {
		return at < b.at;
	}
};

Customer c[MAXN];
int n, k;
int wt[MAXN];
queue<int> w[100];

void serve() {
	sort(c, c + n);

	int tot = 0;
	for (int i = 8 * 3600; i <= 36 * 3600; ++i) { // 24小时还不够，居然服务到过夜啊，瞎了。
		for (int j = 0; j < k; ++j) {
			if (!w[j].empty() && wt[j] + c[ w[j].front() ].pt * 60 == i) {
				w[j].pop();
			}
			if (w[j].empty() && tot < n && c[tot].at <= i) {
				if (c[tot].at > 17 * 3600) return;
				wt[j] = c[tot].dt = i;
				w[j].push(tot++);
			}
		}
	}
}

int main() {
	char t[10];

	scanf("%d %d", &n, &k);
	for (int i = 0, h, m, s; i < n; ++i) {
		scanf("%s", t); sscanf(t, "%d:%d:%d", &h, &m, &s);
		scanf("%d", &c[i].pt); 
		c[i].at = h * 3600 + m * 60 + s;
	}

	serve();

	int wait = 0, cnt = 0;
	for (int i = 0; i < n; ++i) if (c[i].dt) {
		cnt++, wait += c[i].dt - c[i].at;
	}
	printf("%.1f\n", cnt ? wait / 60.0 / cnt : 0);

	return 0;
}


