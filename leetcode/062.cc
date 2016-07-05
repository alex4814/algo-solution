#include <cstdio>

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (!m || !n) {
      return 0;
    }
    vector<int> f(n, 0);
    f[0] = 1;
    for (int k = 0; k < m; ++k) {
      for (int i = 1; i < n; ++i) {
        f[i] = f[i - 1] + f[i];
      }
    }
    return f[n - 1];
  }
};
