/*
 * Creation Date: 2016-07-06
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
  vector<int> searchRange(vector<int>& nums, int target) {
    int a = lowerBound(nums, target);
    int b = upperBound(nums, target);
    return { a, b };
  }
  int lowerBound(vector<int> &nums, int x) {
    int lo = 0;
    int hi = nums.size();
    if (lo == hi) {
      return -1;
    }
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (nums[mi] >= x) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    return nums[lo] == x ? lo : -1;
  }
  int upperBound(vector<int> &nums, int x) {
    int lo = 0;
    int hi = nums.size();
    if (lo == hi) {
      return -1;
    }
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (nums[mi] <= x) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return nums[hi - 1] == x ? hi - 1 : -1;
  }
};

int main() {

  return 0;
}
