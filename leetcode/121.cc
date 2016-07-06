#include <cstdio>

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ret = 0;
    int low = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
      low = min(low, prices[i]);
      ret = max(ret, prices[i] - low);
    }
    return ret;
  }
};

int main() {

  return 0;
}
