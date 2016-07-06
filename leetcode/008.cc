/*
 * Creation Date: 2016-06-29
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
  bool trunc(string str, string &result) {
    if (str.empty()) {
      return false;
    }
    int n = str.size();
    int lo = 0;
    while (lo < n && isspace(str[lo])) {
      lo += 1;
    }
    int hi = lo;
    if (hi < n && (str[hi] == '-' || str[hi] == '+')) {
      hi += 1;
    }
    if (hi < n && !isdigit(str[hi])) {
      return false;
    }
    while (hi < n && isdigit(str[hi])) {
      hi += 1;
    }
    result = str.substr(lo, hi - lo);
    return true;
  }
  int myAtoi(string str) {
    string p;
    if (!trunc(str, p)) {
      return 0;
    }
    long long ret = 0;
    int n = p.size();
    bool neg = false;
    for (int i = 0; i < n; ++i) {
      if (p[i] == '-') {
        neg = true;
      } else if (p[i] == '+') {
        ;
      } else {
        ret = ret * 10 + (p[i] - '0');
      }
      if (!neg && ret > INT_MAX) {
        return INT_MAX;
      }
      if (neg && ret * -1 < INT_MIN) {
        return INT_MIN;
      }
    }
    return ret * (neg ? -1 : 1);
  }
};

int main() {
  Solution s;
  s.myAtoi("-1233d");
  s.myAtoi("  -3 42");
  return 0;
}

// "0"
// "-1233"
// "  -2147483648"
// "-2147483648"
// "2147483647"
// " +2147483647aa"
// "214748364733"
// "21474836473333333333333333333333333"
// "-d223"
// "-.23"
