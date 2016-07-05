#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

#define MAXN 10005
#define MAXM 105
#define PI acos(-1.0)
#define EPS 1e-8

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<pii> s;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      s.push_back(make_pair(nums[i], i));
    }
    sort(s.begin(), s.end());

    int a, b;
    for (int i = 0; i < n; ++i) {
      int x = s[i].first;
      int y = target - x;
      a = s[i].second;
      b = lower_bound(s.begin() + i + 1, s.end(), make_pair(y, 0)) - s.begin();
      if (s[b].first == y) {
        b = s[b].second;
        break;
      }
    }

    if (a > b) {
      swap(a, b);
    }
    vector<int> ret = {a + 1, b + 1};
    return ret;
  }
};

int main() {
  Solution s = Solution();
  vector<int> a = {-1,-2,-3,-4,-5};
  vector<int> r = s.twoSum(a, -8);
  cout << r[0] << " " << r[1] << endl;
  return 0;
}
