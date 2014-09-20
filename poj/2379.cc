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
#define MAXN 1005
#define MAXP 20

typedef pair<int, int> pii;
typedef long long ll;

struct Team {
	int id;
	int solved[MAXP];
	int penalty[MAXP];
	int nSolved;
	int nPenalty;
	bool operator < (const Team &b) const {
		return (nSolved > b.nSolved)
			|| (nSolved == b.nSolved && nPenalty < b.nPenalty)
			|| (nSolved == b.nSolved && nPenalty == b.nPenalty && id < b.id);
	}
};

struct Submission {
	int c, p, t, r;
	bool operator < (const Submission &b) const {
		return t < b.t;
	}
};

Team t[MAXN];
Submission s[MAXN]; 
int c, n;

int main() {
	int ci, pi, ti, ri;

	while (scanf("%d %d", &c, &n) == 2) {
		memset(t, 0, sizeof(t));
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d %d", &s[i].c, &s[i].p, &s[i].t, &s[i].r);
			s[i].c--, s[i].p--;
		}
		sort(s, s + n);
		for (int i = 0; i < n; ++i) {
			int ci = s[i].c;
			int pi = s[i].p;
			int ti = s[i].t;
			int ri = s[i].r;
			if (t[ci].solved[pi]) continue;
			t[ci].solved[pi] = ti * ri;
			t[ci].penalty[pi] += 1200 * (ri ^ 1);
		}
		for (int i = 0; i < c; ++i) {
			t[i].id = i + 1;
			for (int p = 0; p < MAXP; ++p) {
				if (!t[i].solved[p]) continue;
				t[i].nSolved++, t[i].nPenalty += t[i].solved[p] + t[i].penalty[p];
			}
		}
		sort(t, t + c);
		for (int i = 0; i < c; ++i) {
			printf("%d%c", t[i].id, i + 1 == c ? '\n' : ' ');
		}
	}

	return 0;
}


