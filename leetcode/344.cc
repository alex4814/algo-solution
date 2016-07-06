/*
 * Creation Date: 2016-06-12
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
  string reverseString(string s) {
    int n = s.size();
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
      swap(s[lo++], s[hi--]);
    }
    return s;
  }
};

int main() {

  return 0;
}
