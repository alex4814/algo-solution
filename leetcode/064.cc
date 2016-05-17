#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (!m || !n) return 0;

    int **f = new int*[m];
    for (int i = 0; i < m; ++i) {
      f[i] = new int[n];
      for (int j = 0; j < n; ++j) {
        f[i][j] = grid[i][j];
      }
    }
    for (int i = 1; i < n; ++i) {
      f[0][i] += f[0][i - 1];
    }
    for (int i = 1; i < m; ++i) {
      f[i][0] += f[i - 1][0];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        f[i][j] += min(f[i - 1][j], f[i][j - 1]);
      }
    }
    int x = f[m - 1][n - 1];
    for (int i = 0; i < m; ++i) {
      delete[] f[i];
    }
    delete[] f;
    return x;
  }
};

int main() {
  return 0;
}
