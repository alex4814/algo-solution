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
  int maxProduct(vector<string>& words) {
    vector<int> bits;
    for (string &w: words) {
      bits.push_back(letterBits(w));
    }
    int n = words.size();
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (bits[i] & bits[j]) {
          continue;
        }
        int a = words[i].size();
        int b = words[j].size();
        ret = max(ret, a * b);
      }
    }
    return ret;
  }
  int letterBits(const string &w) {
    int bit = 0;
    for (const char c: w) {
      bit |= 1 << (c - 'a');
    }
    return bit;
  }
};

int main() {

  return 0;
}
