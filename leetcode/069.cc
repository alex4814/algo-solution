/*
 * Creation Date: 2016-04-16
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
  int mySqrt(int x) {
    long long xk = x;
    while (xk * xk > x) {
      xk = (xk + x / xk) >> 1;
    }
    return xk;
  }
};

int main() {

  return 0;
}
