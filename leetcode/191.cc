/*
 * Creation Date: 2016-07-17
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
  int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
      n &= (n - 1);
      ret += 1;
    }
    return ret;
  }
};

int main() {

  return 0;
}
