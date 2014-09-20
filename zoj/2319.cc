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

struct Member {
	int s, b;
	int id;
	bool operator < (const Member &p) const {
		return s < p.s || (s == p.s && b > p.b);
	}
};

Member m[MAXN];
int T, n;
int bd[MAXN], nb;

int f[MAXN], nf;
int p[MAXN];

int lower(int x) {
	int l = 1, r = nf;
	while (l < r) {
		int mid = l + (r - l) / 2;
		m[ f[mid] ].b >= x ? r = mid : l = mid + 1;
	}
	return l;
}

void print(int x) {
	if (x == -1) return;
	printf("%d", m[x].id);
	putchar(p[x] == -1 ? '\n' : ' ');
	print(p[x]);
}

void lis() {
	f[0] = -1;
	nf = 1;
	memset(p, -1, sizeof(p));

	for (int i = 0; i < n; ++i) {
		int pos = lower(m[i].b);
		//printf("pos = %d\n", pos);
		if (pos == nf) {
			p[i] = f[nf - 1];
			f[nf++] = i;
		} else if (m[ f[pos] ].b > m[i].b) {
			p[i] = f[pos - 1];
			f[pos] = i;
		}
	}

	printf("%d\n", nf - 1);
	print(f[nf - 1]);
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &m[i].s, &m[i].b);
			m[i].id = i + 1;
		}
		sort(m, m + n);

		lis();

		if (T) putchar('\n');
	}

	return 0;
}


