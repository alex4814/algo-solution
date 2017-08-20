/*
 * Creation Date: 2016-10-14
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
  void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        board[i][j] *= 9;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] > 8) {
          add(board, i, j, 1);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        board[i][j] = (board[i][j] == 3 || board[i][j] == 11 || board[i][j] == 12);
      }
    }
  }
  void add(vector<vector<int>>& board, int ci, int cj, int val) {
    static int di[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int dj[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int n = board.size();
    for (int i = 0; i < 8; ++i) {
      int ti = ci + di[i];
      int tj = cj + dj[i];
      if (ti >= 0 && ti < n && tj >= 0 && tj < board[0].size()) {
        board[ti][tj] += val;
      }
    }
  }
};

int main() {

  return 0;
}
