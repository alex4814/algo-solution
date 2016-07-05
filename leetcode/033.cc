/*
 * Creation Date: 2016-04-27
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
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;
    int lo = 0, hi = n;
    while (lo < hi) {
      int mi = lo + (hi - lo >> 1);
      if (nums[mi] >= nums[0]) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    int ix = -1;
    if ((ix = bs(nums, 0, lo, target)) != -1) {
      return ix;
    } 
    if ((ix = bs(nums, lo, n, target)) != -1) {
      return ix;
    } 
    return ix;
  }
  int bs(vector<int> &nums, int lo, int hi, int target) {
    while (lo < hi) {
      int mi = lo + (hi - lo >> 1);
      if (nums[mi] == target) return mi;
      nums[mi] < target ? lo = mi + 1 : hi = mi;
    }
    return -1;
  }
};

int main() {

  return 0;
}
