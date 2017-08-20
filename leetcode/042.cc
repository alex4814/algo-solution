/*
 * Creation Date: 2016-07-12
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
  int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
      return 0;
    }
    vector<int> l(n), r(n);
    l[0] = 0;
    for (int i = 1; i < n; ++i) {
      l[i] = max(l[i - 1], height[i - 1]);
    }
    r[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
      r[i] = max(r[i + 1], height[i + 1]);
    }
    int ret = 0;
    for (int i = 1; i < n - 1; ++i) {
      ret += max(min(l[i], r[i]), height[i]) - height[i];
    }
    return ret;
  }
};

int main() {

  return 0;
}
