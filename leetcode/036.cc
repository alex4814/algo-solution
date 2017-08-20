/*
 * Creation Date: 2016-07-06
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
  bool isComponentValid(vector<vector<char>> &board, int ilo, int ihi, int jlo, int jhi) {
    const int n = 9;
    bool occur[n] = { false };
    for (int i = ilo; i < ihi; ++i) {
      for (int j = jlo; j < jhi; ++j) {
        if (board[i][j] == '.') continue;
        int num = board[i][j] - '1';
        if (occur[num]) {
          return false;
        }
        occur[num] = true;
      }
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char>>& board) {
    const int n = 9;
    // columns
    for (int j = 0; j < n; ++j) {
      if (!isComponentValid(board, 0, 9, j, j + 1)) {
        return false;
      }
    }
    // rows
    for (int i = 0; i < n; ++i) {
      if (!isComponentValid(board, i, i + 1, 0, 9)) {
        return false;
      }
    }
    // sub
    for (int k = 0; k < n; ++k) {
      int i = (k % 3) * 3;
      int j = (k / 3) * 3;
      if (!isComponentValid(board, i, i + 3, j, j + 3)) {
        return false;
      }
    }
    return true;
  }
};

int main() {

  return 0;
}
