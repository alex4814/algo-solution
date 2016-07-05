/*
 * Creation Date: 2016-04-12
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
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;
    int ret = nums[0];
    int s = nums[0];
    for (int i = 1; i < n; ++i) {
      s = s >= 0 ? s + nums[i] : nums[i];
      ret = max(ret, s);
    }
    return ret;
  }
};

int main() {

  return 0;
}
