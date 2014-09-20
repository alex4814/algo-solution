/*
ID: alex4814
PROG: ariprog
LANG: C++
*/

#define NDEBUG
#define FILEIO

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 125000
#define EPS 1e-8
#define INF 0x3f3f3f3f

int n, m, k;
int bisqr[MAXN];
vector<pii> ret;
bool in[MAXN + 1];

bool work(int a, int b) {
	if (a + (n - 1) * b > MAXN) return false;
	for (int i = 0; i < n; ++i) {
		if (!in[a + i * b]) return false;
	}
	return true;
}

int main() {
#ifdef FILEIO
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	for (int p = 0; p <= m; ++p) {
		for (int q = p; q <= m; ++q) {
			in[p * p + q * q] = true;
			bisqr[k++] = p * p + q * q;
		}
	}
	sort(bisqr, bisqr + k);
	k = unique(bisqr, bisqr + k) - bisqr;

	for (int i = 0; i < k; ++i) {
		for (int j = i + 1; j < k; ++j) {
			if (work(bisqr[i], bisqr[j] - bisqr[i])) {
				ret.push_back(make_pair(bisqr[j] - bisqr[i], bisqr[i]));
			}
		}
	}

	sort(ret.begin(), ret.end());
	int sz = ret.size();
	if (sz == 0) {
		printf("NONE\n");
	} else {
		for (int i = 0; i < sz; ++i) {
			printf("%d %d\n", ret[i].second, ret[i].first);
		}
	}

	return 0;
}
