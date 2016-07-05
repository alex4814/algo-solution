#include <cstdio>

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    int ret = 0;
    int low = prices[0], temp;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < low) {
        low = prices[i];
      } else {
        temp = prices[i] - low;
        ret = max(ret, temp);
      }
    }
    return ret;
  }
};

int main() {

  return 0;
}
