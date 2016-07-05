/*
 * Creation Date: 2016-04-17
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
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; ++i) {
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (abs(sum - target) < abs(ret - target)) {
          if ((ret = sum) == target) {
            return ret;
          }
        }
        sum < target ? ++j : --k;
      }
    }
    return ret;
  }
};

int main() {

  return 0;
}
