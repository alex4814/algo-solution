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
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int m = matrix.size();
    int n = matrix[0].size();
    bool r = false;
    bool c = false;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j]) continue;
        matrix[i][0] = matrix[0][j] = 0;
        if (!i) r = true;
        if (!j) c = true;
      }
    }
    for (int i = 1; i < m; ++i) {
      if (matrix[i][0]) continue;
      for (int j = 1; j < n; ++j) {
        matrix[i][j] = 0;
      }
    }
    for (int j = 1; j < n; ++j) {
      if (matrix[0][j]) continue;
      for (int i = 1; i < m; ++i) {
        matrix[i][j] = 0;
      }
    }
    if (r) {
      for (int j = 0; j < n; ++j) {
        matrix[0][j] = 0;
      }
    }
    if (c) {
      for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};

int main() {

  return 0;
}
