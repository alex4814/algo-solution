/*
 * Creation Date: 2016-07-24
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
  bool increasingTriplet(vector<int>& nums) {
    int l1 = INT_MAX;
    int l2 = INT_MAX;
    for (int x: nums) {
      if (x > l2) {
        return true;
      }
      if (x > l1) {
        l2 = min(l2, x);
      }
      l1 = min(l1, x);
    }
    return false;
  }
};

int main() {

  return 0;
}
