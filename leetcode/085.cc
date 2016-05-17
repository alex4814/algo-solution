/*
 * Creation Date: 2016-04-11
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
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (!n) return 0;

    int m = matrix[0].size();
    unique_ptr<int[]> h(new int[m] {0});
    unique_ptr<int[]> l(new int[m] {0});
    unique_ptr<int[]> r(new int[m] {0});
    
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      // modify original vectors
      for (int j = 0; j < m; ++j) {
        matrix[i][j] -= '0';
      }
      for (int j = 0; j < m; ++j) {
        h[j] = matrix[i][j] ? h[j] + 1 : 0;
      }
      l[0] = matrix[i][0] ? 0 : -1;
      for (int j = 1; j < m; ++j) {
        if (!matrix[i][j]) {
          l[j] = -1;
          continue;
        }
        int x = j - 1;
        while (x >= 0 && h[j] <= h[x]) {
          l[j] = l[x];
          x = l[j] - 1;
        }
        if (x == j - 1) {
          l[j] = j;
        }
      }
      r[m - 1] = matrix[i][m - 1] ? m - 1 : -1;
      for (int j = m - 2; j >= 0; --j) {
        if (!matrix[i][j]) {
          r[j] = -1;
          continue;
        }
        int x = j + 1;
        while (x < m && h[j] <= h[x]) {
          r[j] = r[x];
          x = r[j] + 1;
        }
        if (x == j + 1) {
          r[j] = j;
        }
      }
      for (int j = 0; j < m; ++j) {
        if (!matrix[i][j]) continue;
        ret = max(ret, (r[j] - l[j] + 1) * h[j]);
      }
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  vector<vector<char>> x = {
    {1,1,1}, {1,1,1},{0,0,1}
  };
  vector<vector<char>> y = {
    {'0','0','0'}
  };
  cout << s.maximalRectangle(x) << endl;
  cout << s.maximalRectangle(y) << endl;
  return 0;
}
