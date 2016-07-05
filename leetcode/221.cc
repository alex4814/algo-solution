/*
 * Creation Date: 2016-04-12
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
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (!n) return 0;
    int m = matrix[0].size();
    if (!m) return 0;

    int ret = 0;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (matrix[i - 1][j - 1] == '1') {
          f[i][j] = min(f[i - 1][j], f[i][j - 1]);
          f[i][j] = min(f[i][j], f[i - 1][j - 1]) + 1;
        }
        ret = max(ret, f[i][j]);
      }
    }
    return ret * ret;
  }
};

int main() {

  return 0;
}
