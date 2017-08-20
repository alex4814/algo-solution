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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    if (numRows <= 0) {
      return pascal;
    }
    pascal.push_back({ 1 });
    for (int i = 1; i < numRows; ++i) {
      vector<int> row;
      int n = pascal[i - 1].size();
      for (int j = 0; j <= n; ++j) {
        int a = j - 1 < 0 ? 0 : pascal[i - 1][j - 1];
        int b = j == n ? 0 : pascal[i - 1][j];
        row.push_back(a + b);
      }
      pascal.push_back(row);
    }
    return pascal;
  }
};

int main() {

  return 0;
}
