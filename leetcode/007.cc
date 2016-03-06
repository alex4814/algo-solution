#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    if (x == INT_MIN) {
      return 0;
    }
    bool neg = x < 0;
    x = abs(x);

    vector<int> d;
    while (x > 0) {
      d.push_back(x % 10);
      x /= 10;
    }
    int r = 0;
    for (const int digit: d) {
      if (INT_MAX / 10 < r) {
        return 0;
      }
      r = r * 10 + digit;
      if (r < 0) {
        return 0;
      }
    }
    return r * (neg ? -1 : 1);
  }
};

int main() {
  Solution s = Solution();
  cout << s.reverse(0) << endl;
  cout << s.reverse(100) << endl;
  cout << s.reverse(2147483647) << endl;
  cout << s.reverse(-2147483648) << endl;
  cout << s.reverse(-2147483647) << endl;
  cout << s.reverse(2342) << endl;
  cout << s.reverse(-223) << endl;
  cout << s.reverse(1000000003) << endl;
  return 0;
}
