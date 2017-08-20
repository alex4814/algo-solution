/*
 * Creation Date: 2016-09-17
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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> mat;
    if (n <= 0) {
      return mat;
    }
    vector<int> row(n, 0);
    for (int i = 0; i < n; ++i) {
      mat.push_back(row);
    }
    int cd = 0, ci = 0, cj = 0;
    int x = 1;
    for (int k = 0; k < n * n; ++k) {
      mat[ci][cj] = x++;
      next_pos(n, ci, cj, cd, mat);
    }
    return mat;
  }
private:
  void next_pos(int n, int &ci, int &cj, int &cd, vector<vector<int>> &mat) {
    int ni = ci + di[cd];
    int nj = cj + dj[cd];
    if (!valid(ni, nj, n, mat)) {
      cd = (cd + 1) % 4;
      ni = ci + di[cd];
      nj = cj + dj[cd];
    }
    ci = ni, cj = nj;
  }
  bool valid(int i, int j, int n, vector<vector<int>> &mat) {
    return i >= 0 && i < n && j >= 0 && j < n && mat[i][j] == 0;
  }
  int di[4] = {0, 1, 0, -1};
  int dj[4] = {1, 0, -1, 0};
};

int main() {
  Solution s;
  auto mat = s.generateMatrix(5);
  for (auto row: mat) {
    for (auto ele: row) {
      cout << " " << ele;
    }
    cout << endl;
  }
  return 0;
}
