/*
 * Creation Date: 2016-08-17
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
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> vis(n, vector<int>(n, false));
    vector<vector<string>> ret;
    vector<string> board(n, string(n, '.'));
    solve(0, n, board, vis, ret);
    return ret;
  }
  void solve(int row, int n, 
      vector<string> &board, 
      vector<vector<int>> &vis, 
      vector<vector<string>> &ret) {
    if (row == n) {
      ret.push_back(board);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (vis[row][i] > 0) continue;
      board[row][i] = 'Q';
      set_attack(row, i, n, vis, 1);
      solve(row + 1, n, board, vis, ret);
      board[row][i] = '.';
      set_attack(row, i, n, vis, -1);
    }
  }
  void set_attack(int row, int col, int n, vector<vector<int>> &vis, int val) {
    for (int i = 0; i < n; ++i) {
      vis[i][col] += val;
      vis[row][i] += val;
      // diag
      if (row - i >= 0 && row - i < n && col - i >= 0 && col - i < n) {
        vis[row - i][col - i] += val;
      }
      if (row + i >= 0 && row + i < n && col + i >= 0 && col + i < n) {
        vis[row + i][col + i] += val;
      }
      if (row - i >= 0 && row - i < n && col + i >= 0 && col + i < n) {
        vis[row - i][col + i] += val;
      }
      if (row + i >= 0 && row + i < n && col - i >= 0 && col - i < n) {
        vis[row + i][col - i] += val;
      }
      vis[row][col] -= 5 * val;
    }
  }
};

int main() {
  Solution s;
  for (int i = 1; i < 5; ++i) {
    printf("--------- Case: %02d ----------\n", i);
    auto ret = s.solveNQueens(i);
    for (auto f: ret) {
      for (auto d: f) {
        cout << d << endl;
      }
      cout << endl;
    }
    printf("--------- Case: %02d END ----------\n", i);
  }
  return 0;
}
