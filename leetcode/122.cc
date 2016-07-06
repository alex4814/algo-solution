/*
 * Creation Date: 2016-06-13
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
  int maxProfit(vector<int>& prices) {
    int ret = 0;
    for (int i = 1; i < prices.size(); ++i) {
      ret += max(prices[i] - prices[i - 1], 0);
    }
    return ret;
  }
};

int main() {

  return 0;
}
