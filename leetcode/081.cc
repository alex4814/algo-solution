/*
 * Creation Date: 2016-10-08
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
  bool search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size();
    while (lo < hi) {
      int mi = lo + ((hi - lo) >> 1);
      if (nums[mi] == target) {
        return true;
      }
      if (nums[mi] == nums[lo] && nums[mi] == nums[hi - 1]) {
        lo += 1;
        hi -= 1;
      } else if (nums[lo] <= nums[mi]) {
        if (target >= nums[lo] && target < nums[mi]) {
          hi = mi;
        } else {
          lo = mi + 1;
        }
      } else {
        if (target > nums[mi] && target <= nums[hi - 1]) {
          lo = mi + 1;
        } else {
          hi = mi;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> d {1, 1, 1, 3, 1};
  cout << s.search(d, 5) << endl;
  cout << s.search(d, 6) << endl;
  cout << s.search(d, 3) << endl;
  cout << s.search(d, 2) << endl;
  cout << s.search(d, 1) << endl;
  return 0;
}
