/*
 * Creation Date: 2016-04-11
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
  int numDecodings(string s) {
    int n = s.size();
    unique_ptr<int[]> f(new int[n + 1]);
    if (n == 0) {
      return 0;
    }
    f[0] = 1;
    if (n > 0) {
      f[1] = (s[0] != '0');
    }
    for (int i = 1; i < n; ++i) {
      if (f[i] == 0) {
        return 0;
      }
      if (s[i] == '0') {
        f[i + 1] = (s[i - 1] == '1' || s[i - 1] == '2') ? f[i - 1] : 0; 
      } else {
        f[i + 1] = f[i];
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] > '0' && s[i] <= '6')) {
          f[i + 1] += f[i - 1];
        }
      }
    }
    return f[n];
  }
};

int main() {

  return 0;
}
