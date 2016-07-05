#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

class Solution {
public:
  bool isVectorEqual(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) return false;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> r;
    vector<int> quad;

    sort(nums.begin(), nums.end());
    //num = preprocess(num);
    int n = nums.size();
    for (int i = 0; i <= n - 4; ++i) {
      quad.push_back(nums[i]);
      searchFourSum(i + 1, n, 3, target - nums[i], nums, quad, r);
      quad.pop_back();
    }

    vector<vector<int>> ret;
    int sz = r.size();
    if (sz > 0) {
      ret.push_back(r[0]);
      for (int i = 1; i < sz; ++i) {
        if (!isVectorEqual(r[i], r[i - 1])) {
          ret.push_back(r[i]);
        }
      }
    }
    return ret;
  }
  void searchFourSum(int k, int n, int left, int target, vector<int> &nums, vector<int> &quad, vector<vector<int>> &r) {
    if (target == 0 && left == 0) {
      r.push_back(quad);
      return;
    }
    if (target < 0 || left <= 0) {
      return;
    }
    for (int i = k; i < n; ++i) {
      if (nums[i] > target) break;
      quad.push_back(nums[i]);
      searchFourSum(i + 1, n, left - 1, target - nums[i], nums, quad, r);
      quad.pop_back();
    }
  }
};

int main() {
  vector<int> g{-489,-475,-469,-468,-467,-462,-456,-443,-439,-425,-425,-410,-401,-342,-341,-331,-323,-307,-299,-262,-254,-245,-244,-238,-229,-227,-225,-224,-221,-197,-173,-171,-160,-142,-142,-136,-134,-125,-114,-100,-86,-81,-66,-47,-37,-34,4,7,11,34,60,76,99,104,113,117,124,139,141,143,144,146,157,157,178,183,185,189,192,194,221,223,226,232,247,249,274,281,284,293,298,319,327,338,340,368,375,377,379,388,390,392,446,469,480,490};
  Solution s = Solution();
  vector<vector<int>> r = s.fourSum(g, 2738);
  for (int i = 0; i < (int)r.size(); ++i) {
    for (int k = 0; k < 4; ++k) {
      printf("%d ", r[i][k]);
    }
    putchar('\n');
  }
  return 0;
}

