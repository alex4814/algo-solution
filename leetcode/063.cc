#include <cstdio>
#include <vector>
using namespace std;


class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    if (!m) {
      return 0;
    }
    int n = obstacleGrid[0].size();
    if (!n || obstacleGrid[0][0]) {
      return 0;
    }
    f[0][0] = 1;
    for (int j = 1; j < n; ++j) {
      f[0][j] = obstacleGrid[0][j] ? 0 : f[0][j - 1];
    }
    for (int i = 1; i < m; ++i) {
      f[i][0] = obstacleGrid[i][0] ? 0 : f[i - 1][0];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j]) {
          f[i][j] = 0;
        } else {
          f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
      }
    }
    return f[m - 1][n - 1];
  }
private:
  static const int N = 105;
  int f[N][N];
};

int main() {
  return 0;
}
