/*
 * Creation Date: 2016-05-17
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
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int len = 0;
    for (int i = 0; i < n; ++i) {
      if (len && nums[len - 1] == nums[i]) {
        continue;
      }
      nums[len++] = nums[i];
    }
    return len;
  }
};

int main() {

  return 0;
}
