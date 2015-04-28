#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

#define MAXN 1005

int w, n;
vector<pii> rle;
vector<int> seq;
vector<pii> ret;

inline void mark(int ix) {
	seq.push_back(ix);
	if (ix - w >= 0) seq.push_back(ix - w);
	if (ix + w < n) seq.push_back(ix + w);
}

inline int value_of(int ix) {
	int l = 0, r = rle.size();
	while (l < r) {
		int m = l + (r - l) / 2;
		rle[m].first <= ix ? l = m + 1 : r = m;
	}
	return rle[r - 1].second;
}

int cal(int ix) {
	int _i = ix / w, _j = ix % w;
	int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
	int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
	int v[9], ret = 0;
	for (int i = 0; i < 9; ++i) {
		v[i] = -1;
		int ti = _i + dx[i];
		int tj = _j + dy[i];
		if (ti < 0 || ti >= n / w || tj < 0 || tj >= w) continue;
		v[i] = value_of(w * ti + tj);
	}
	for (int i = 0; i < 9; ++i) {
		if (v[i] == -1) continue;
		ret = max(ret, abs(v[4] - v[i]));
	}
	return ret;
}

int main() {
	int sz;
	while (scanf("%d", &w), w) {
		rle.clear();
		seq.clear();
		ret.clear();

		int v, l, b = 0;
		while (scanf("%d %d", &v, &l)) {
			if (!v && !l) break;
			rle.push_back(make_pair(b, v));
			b += l;
		}
		n = b;

		sz = rle.size();
		for (int i = 0; i < sz; ++i) {
			mark(rle[i].first);
			mark(i + 1 == sz ? n - 1 : rle[i + 1].first - 1);
		}
		sort(seq.begin(), seq.end());
		seq.resize(distance(seq.begin(), unique(seq.begin(), seq.end())));

		sz = seq.size();
		for (int i = 0; i < sz; ++i) {
			ret.push_back(make_pair(seq[i], cal(seq[i])));
			if (seq[i] + 1 >= 0 && seq[i] + 1 < n) {
				ret.push_back(make_pair(seq[i] + 1, cal(seq[i] + 1)));
			}
		}
		sort(ret.begin(), ret.end());
		ret.resize(distance(ret.begin(), unique(ret.begin(), ret.end())));

		int k = 1;
		sz = ret.size();
		for (int i = 1; i < sz; ++i) {
			if (ret[i].second != ret[i - 1].second) {
				ret[k++] = ret[i];
			}
		}
		ret.resize(k);

		printf("%d\n", w);
		for (int i = 1; i < k; ++i) {
			printf("%d %d\n", ret[i - 1].second, ret[i].first - ret[i - 1].first);
		}
		printf("%d %d\n0 0\n", ret[k - 1].second, n - ret[k - 1].first);
	}
	printf("0\n");

	return 0;
}
