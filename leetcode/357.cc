/*
 * Creation Date: 2016-06-19
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
  int countNumbersWithUniqueDigits(int n) {
    int ret = 1;
    int cnt = 1;
    int availableDigits = 9;
    for (int i = 0; i < n; ++i) {
      if (availableDigits == 0) {
        break;
      }
      cnt *= availableDigits;
      ret += cnt;
      if (i > 0) {
        availableDigits -= 1;
      }
    }
    return ret;
  }
};

int main() {
  Solution s;
  cout << s.countNumbersWithUniqueDigits(1) << endl;
  cout << s.countNumbersWithUniqueDigits(2) << endl;
  cout << s.countNumbersWithUniqueDigits(5) << endl;
  cout << s.countNumbersWithUniqueDigits(10) << endl;
  cout << s.countNumbersWithUniqueDigits(38) << endl;
  return 0;
}
