#include <cstdio>

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;
    int x = 1, y = 1, z;
    for (int i = 1; i < n; ++i) {
      z = x + y;
      x = y;
      y = z;
    }
    return z;
  }
};

int main() {
  return 0;
}
