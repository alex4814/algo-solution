/*
 * Creation Date: 2016-05-01
 * Created By: alex4814
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    vector<vector<int>> ret = {nums};
    int n = factorial(nums.size());
    while (--n) {
      next_permutation(nums);
      ret.push_back(nums);
    }
    return ret;
  }
  int factorial(int x) {
    int ret = 1;
    for (int i = 2; i <= x; ++i) {
      ret *= i;
    }
    return ret;
  }
  void next_permutation(vector<int> &nums) {
    int ix = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        ix = i; break;
      }
    }
    if (ix == -1) {
      reverse(begin(nums), end(nums));
      return;
    }
    for (int i = nums.size() - 1; i > ix; --i) {
      if (nums[i] > nums[ix]) {
        swap(nums[i], nums[ix]);
        reverse(begin(nums) + ix + 1, end(nums));
        break;
      }
    }
  }
};

int main() {

  return 0;
}
