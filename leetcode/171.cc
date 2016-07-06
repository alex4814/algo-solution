/*
 * Creation Date: 2016-06-27
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
  int titleToNumber(string s) {
    int n = s.size();
    int idx = 0;
    for (int i = 0; i < n; ++i) {
      idx = idx * 26 + (s[i] - 'A' + 1);
    }
    return idx;
  }
};

int main() {
  Solution s;
  cout << s.titleToNumber("AA") << endl;
  cout << s.titleToNumber("A") << endl;
  cout << s.titleToNumber("ZZ") << endl;
  cout << s.titleToNumber("AAA") << endl;
  return 0;
}
