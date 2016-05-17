#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define EPS 1e-8

class Solution {
#define MAXN 1005
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (i == m - 1 && j == n - 1) {
          continue;
        }
        if (i == m - 1) {
          dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
        } else if (j == n - 1) {
          dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
        } else {
          int a = max(1, dp[i][j + 1] - dungeon[i][j]);
          int b = max(1, dp[i + 1][j] - dungeon[i][j]);
          dp[i][j] = min(a, b);
        }
      }
    }
    return dp[0][0];
  }
private:
  int dp[MAXN][MAXN];
};

int main() {
  vector<int> a = { -2, -3, 3 };
  vector<int> b = { -5, -10, 1 };
  vector<int> c = { 10, 30, -5 };
  vector<vector<int>> r;
  r.push_back(a);
  r.push_back(b);
  r.push_back(c);

  Solution s = Solution();
  int ss = s.calculateMinimumHP(r);
  printf("%d\n", ss);
  return 0;
}

