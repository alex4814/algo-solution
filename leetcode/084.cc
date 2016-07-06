/*
 * Creation Date: 2016-06-29
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
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    vector<int> lo(n), hi(n);
    lo[0] = -1;
    for (int i = 1; i < n; ++i) {
      int p = i - 1;
      while (p != -1 && heights[i] <= heights[p]) {
        p = lo[p];
      }
      lo[i] = p;
    }
    hi[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
      int p = i + 1;
      while (p != n && heights[i] <= heights[p]) {
        p = hi[p];
      }
      hi[i] = p;
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      ret = max(ret, heights[i] * (hi[i] - lo[i] - 1));
    }
    return ret;
  }
};

int main() {

  return 0;
}
