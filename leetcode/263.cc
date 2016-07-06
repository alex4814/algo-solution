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
  bool isUgly(int num) {
    if (num <= 0) {
      return false;
    }
    while (num % 2 == 0) {
      num /= 2;
    }
    while (num % 3 == 0) {
      num /= 3;
    }
    while (num % 5 == 0) {
      num /= 5;
    }
    return num == 1;
  }
};

int main() {

  return 0;
}
