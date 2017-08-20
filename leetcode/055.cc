/*
 * Creation Date: 2016-08-18
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
  bool canJump(vector<int>& nums) {
    int p = 0, n = nums.size();
    for (int reach = 0; p < n && p <= reach; ++p) {
      reach = max(reach, p + nums[p]);
    }
    return p == n;
  }
};

int main() {

  return 0;
}
