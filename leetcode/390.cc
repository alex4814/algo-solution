/*
 * Creation Date: 2016-10-14
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
  int lastRemaining(int n) {
    return helper(n, 0);
  }
  int helper(int n, int d) {
    if (n <= 1) {
      return n;
    }
    return (helper(n / 2, d ^ 1) << 1) - (d == 1 && !(n & 1));
  }
};

int main() {
  Solution s;
  for (int i = 1; i < 20; ++i) {
    cout << s.lastRemaining(i) << endl;
  }
  return 0;
}
