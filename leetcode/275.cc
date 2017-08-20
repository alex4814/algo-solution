/*
 * Creation Date: 2016-07-24
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
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    int lo = 0;
    int hi = n;
    
    while (lo < hi) {
      int mi = lo + ((hi - lo) >> 1);
      if (n - mi <= citations[mi]) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    return n - lo;
  }
};

int main() {

  return 0;
}
