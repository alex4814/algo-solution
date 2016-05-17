/*
 * Creation Date: 2016-04-25
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
#include <unordered_set>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    unique_ptr<bool[]> f(new bool[n + 1] { false });
    f[0] = true;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
        if (f[j] == false) continue;
        string str = s.substr(j, i - j + 1);
        f[i + 1] |= (wordDict.find(str) != wordDict.end());
        if (f[i + 1]) break;
      }
    }
    return f[n];
  }
};

int main() {

  return 0;
}
