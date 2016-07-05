/*
 * Creation Date: 2016-04-19
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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    if (matrix.empty()) return ret;
    int m = matrix.size();
    int n = matrix[0].size();
    int loop = (min(m, n) + 1) >> 1;
    for (int i = 0; i < loop; ++i) {
      print_loop(matrix, i, m, n, ret);
    }
    return ret;
  }
  void print_loop(vector<vector<int>> &matrix, int ith, int m, int n, vector<int> &ret) {
    // left to right
    for (int j = ith; j < n - ith; ++j) {
      ret.push_back(matrix[ith][j]);
    }
    // top to down
    for (int i = ith + 1; i < m - 1 - ith; ++i) {
      ret.push_back(matrix[i][n - 1 - ith]);
    }
    // right to left
    if (m - 1 - ith != ith) {
      for (int j = n - 1 - ith; j >= ith; --j) {
        ret.push_back(matrix[m - 1 - ith][j]);
      }
    }
    // down to top
    if (n - 1 - ith != ith) {
      for (int i = m - 2 - ith; i > ith; --i) {
        ret.push_back(matrix[i][ith]);
      }
    }
  }
};

int main() {

  return 0;
}
