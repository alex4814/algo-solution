/*
 * Creation Date: 2016-07-09
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
  Solution() {
    const string symbols = "IVXLCDM";
    mappings['I' - 'A'] = 1;
    for (int i = 1; i < symbols.size(); ++i) {
      mappings[symbols[i] - 'A'] = mappings[symbols[i - 1] - 'A'] * (i & 1 ? 5 : 2);
    }
  }
  int romanToInt(string s) {
    int ret = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      ret += mappings[s[i] - 'A'];
      if (i > 0 && mappings[s[i] - 'A'] > mappings[s[i - 1] - 'A']) {
        ret -= mappings[s[i - 1] - 'A'] << 1;
      }
    }
    return ret;
  }
private:
  int mappings[26];
};

int main() {

  return 0;
}
