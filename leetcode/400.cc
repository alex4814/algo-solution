/*
 * Creation Date: 2016-09-25
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
  int findNthDigit(int n) {
    vector<long long> segs = { 0 };
    long long num = 9;
    for (int i = 1; ; ++i, num *= 10) {
      long long x = i * num + segs.back();
      if (x > INT_MAX) {
        break;
      }
      segs.push_back(x);
    }
    auto pos = lower_bound(segs.begin(), segs.end(), n) - segs.begin();
    auto x = (n - segs[pos - 1] - 1) / pos;
    auto y = (n - segs[pos - 1] - 1) % pos;
    auto ret = get_digit(pos - 1, x, y);
    return ret;
  }
  int get_digit(int e, int x, int y) {
    int b = 1;
    for (int i = 0; i < e; ++i) {
      b *= 10;
    }
    b = b + x;
    string s = to_string(b);
    return s[y] - '0';
  }
};

int main() {
  Solution s;
  cout << s.findNthDigit(3) << endl;
  cout << s.findNthDigit(9) << endl;
  cout << s.findNthDigit(10) << endl;
  cout << s.findNthDigit(3329) << endl;
  cout << s.findNthDigit(2147482333) << endl;
  return 0;
}
