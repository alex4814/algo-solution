#include <cstdio>

class Solution {
public:
  int nthUglyNumber(int n) {
    if (n >= N) {
      return INT_MAX;
    }
    int factors[] = { 2, 3, 5 };
    f[0] = 1;
    for (int i = 1; i < n; ++i) {
      int x = INT_MAX; // maximum
      for (int j = i - 1; j >= 0 && f[j] > f[i - 1]/5; --j) {
        if (f[j] >= x/2) continue;
        for (int k = 0; k < 3; ++k) {
          int m = f[j] * factors[k];
          if (m > 0 && m > f[i - 1] && m < x) {
            x = m; break;
          }
        }
      }
      f[i] = x;
    }
    return f[n - 1];
  }
private:
  static const int N = 2000;
  int f[N];
};

int main() {
  return 0;
}
