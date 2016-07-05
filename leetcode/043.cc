/*
 * Creation Date: 2016-04-24
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
  string multiply(string num1, string num2) {
    auto s1 = num1.size();
    auto s2 = num2.size();
    vector<int> mul(s1 + s2, 0);
    for (int i = s1 - 1; i >= 0; --i) {
      for (int j = s2 - 1; j >= 0; --j) {
        int k = i + j + 1;
        mul[k] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    for (int i = s1 + s2 - 1; i > 0; --i) {
      mul[i - 1] += mul[i] / 10;
      mul[i] %= 10;
    }
    string ret;
    bool start = false;
    for (int i = 0; i < s1 + s2; ++i) {
      if (!start && !mul[i]) continue;
      start = true;
      ret += mul[i] + '0';
    }
    return start ? ret : "0";
  }
};

int main() {
  Solution s;
  cout << s.multiply("12", "12") << endl;
  return 0;
}
