#include <cstdio>

class Solution {
public:
  double myPow(double x, int n) {
    if (n < 0) {
      x = 1 / x;
      n = -n;
    }
    double ret = n < 0 ? (n = ~n), x : 1;
    while (n > 0) {
      if (n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
    return ret;
  }
};

int main() {
  return 0;
}
