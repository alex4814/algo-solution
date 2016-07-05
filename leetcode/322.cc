/*
 * Creation Date: 2016-04-11
 * Last Modified:
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
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int *f = new int[amount + 1];
    f[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 1; i <= amount; ++i) {
      f[i] = -1;
      for (int j = 0; j < n; ++j) {
        int p = i - coins[j];
        if (p < 0) break;
        if (f[p] == -1) continue;
        if (f[i] == -1 || f[i] > f[p] + 1) {
          f[i] = f[p] + 1;
        }
      }
    }
    int r = f[amount];
    delete[] f;
    return r;
  }
};

int main() {

  return 0;
}
