#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
	int id, d, c;
	Candidate(int id, int d, int c): id(id), d(d), c(c) {}
	bool operator < (const Candidate &b) const {
		if (d + c == b.d + b.c) {
			return d == b.d ? id < b.id : d > b.d;
		}
		return d + c > b.d + b.c;
	}
};

vector<Candidate> g[4];
int n, l, h;

int main() {
	scanf("%d%d%d", &n, &l, &h);
	for (int i = 0, id, d, c; i < n; ++i) {
		scanf("%d%d%d", &id, &d, &c);
		if (d < l || c < l) continue;
		if (d >= h && c >= h) {
			g[0].push_back(Candidate(id, d, c));
		} else if (c < h && d >= h) {
			g[1].push_back(Candidate(id, d, c));
		} else if (c < h && d < h && d >= c) {
			g[2].push_back(Candidate(id, d, c));
		} else {
			g[3].push_back(Candidate(id, d, c));
		}
	}
	int m = 0;
	for (int i = 0; i < 4; ++i) {
		sort(g[i].begin(), g[i].end());
		m += (int)g[i].size();
	}
	printf("%d\n", m);
	for (int i = 0; i < 4; ++i) {
		int sz = (int)g[i].size();
		for (int j = 0; j < sz; ++j) {
			printf("%d %d %d\n", g[i][j].id, g[i][j].d, g[i][j].c);
		}
	}

	return 0;
}
