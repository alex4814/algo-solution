/*
 * Creation Date: 2016-07-19
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
  int calculate(string s) {
    vector<int> val;
    char op = '+';
    int num = 0;
    s += '+';
    for (const char d: s) {
      if (isdigit(d)) {
        num = num * 10 + d - '0';
      } else if (d != ' ') {
        if (op == '+') {
          val.push_back(num);
        } else if (op == '-') {
          val.push_back(-num);
        } else {
          int back = val.back();
          val.pop_back();
          val.push_back(op == '*' ? back * num : back / num);
        }
        op = d;
        num = 0;
      }
    }
    int ret = 0;
    for (int x: val) {
      ret += x;
    }
    return ret;
  }
};

int main() {
  Solution s;
  cout << s.calculate("2-3 *4/5 + 44") << endl;
  return 0;
}
