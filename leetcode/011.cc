#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
typedef pair<int, int> pii;
public:
	int maxArea(vector<int>& height) {
		vector<pii> hi;
		size_t n = height.size();
		for (size_t i = 0; i < n; ++i) {
			hi.push_back(make_pair(height[i], i + 1));
		}
		sort(hi.begin(), hi.end());
		vector<int> fmax(n, 0), fmin(n, 0);
		fmin[n - 1] = fmax[n - 1] = hi[n - 1].second;
		for (size_t i = n - 2; i >= 0; --i) {
			fmax[i] = max(hi[i].second, fmax[i + 1]);
			fmin[i] = min(hi[i].second, fmin[i + 1]);
		}
		int ret = 0;
		for (size_t i = 0; i < n - 1; ++i) {
			int d1 = abs(fmax[i + 1] - hi[i].second);
			int d2 = abs(fmin[i + 1] - hi[i].second);
			int d = max(d1, d2);
			ret = max(ret, d * hi[i].first);
		}
		return ret;
	}
};

int main() {
	Solution s = Solution();
	vector<int> d = {1,45,3,4,566,78,10};
	printf("%d\n", s.maxArea(d));
	return 0;
}
