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
    if (matrix.empty()) {
      return 0;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> h(m), l(m), r(m);

    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        h[j] = matrix[i][j] == '1' ? h[j] + 1 : 0;
      }
      l[0] = -1;
      for (int j = 1; j < m; ++j) {
        int p = j - 1;
        while (p != -1 && h[j] <= h[p]) {
          p = l[p];
        }
        l[j] = p;
      }
      r[m - 1] = m;
      for (int j = m - 2; j >= 0; --j) {
        int p = j + 1;
        while (p != m && h[j] <= h[p]) {
          p = r[p];
        }
        r[j] = p;
      }
      for (int j = 0; j < m; ++j) {
        ret = max(ret, h[j] * (r[j] - l[j] - 1));
      }
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  vector<vector<char>> x = {
    {'1','1','1','1'}, {'0','1','1','1'}
  };
  vector<vector<char>> y = {
    {'0','0','0'}, {'1','1','0'}
  };
  cout << s.maximalRectangle(x) << endl;
  cout << s.maximalRectangle(y) << endl;
  return 0;
}
