/*
 * Creation Date: 2016-06-24
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
  string say(string num) {
    string ret;
    int n = num.size();
    for (int i = 0; i < n; ++i) {
      int j = i;
      while (j + 1 < n && num[i] == num[j + 1]) {
        j += 1;
      }
      ret += to_string(j + 1 - i) + num[j];
      i = j;
    }
    return ret;
  }
  string countAndSay(int n) {
    if (n <= 0) {
      return "";
    }
    string ret = "1";
    for (int i = 1; i < n; ++i) {
      ret = say(ret);
    }
    return ret;
  }
};

int main() {
  Solution s;
  cout << s.countAndSay(4) << endl;
  return 0;
}
