#include <cstdio>
#include <vector>
using namespace std;


class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if (!n) {
      return 0;
    }
    vector<int> f(n, 0);
    f[0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
        if (!j) {
          f[j] = f[j] + triangle[i][j];
        } else if (j == i) {
          f[j] = f[j - 1] + triangle[i][j];
        } else {
          f[j] = min(f[j - 1], f[j]) + triangle[i][j];
        }
      }
    }
    int ret = f[0];
    for (int i = 1; i < n; ++i) {
      ret = min(ret, f[i]);
    }
    return ret;
  }
};

int main() {
  return 0;
}
