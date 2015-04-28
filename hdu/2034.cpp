#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define _N 105


int main() {
	int n, m, t;

	while (scanf("%d%d", &n, &m) == 2) {
		if (!n && !m) break;

		vector<int> a, b, ret;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &t);
			a.push_back(t);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", &t);
			b.push_back(t);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int i = 0; i < n; ++i) {
			if (!binary_search(b.begin(), b.end(), a[i])) {
				ret.push_back(a[i]);
			}
		}
		if ((int)ret.size() == 0) {
			printf("NULL\n");
		} else {
			sort(ret.begin(), ret.end());
			for (int i = 0; i < (int)ret.size(); ++i) {
				printf("%d ", ret[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
