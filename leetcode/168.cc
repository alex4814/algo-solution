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
  string convertToTitle(int n) {
    string title;
    while (n > 0) {
      title += (n - 1) % 26 + 'A';
      n = (n - 1) / 26;
    }
    reverse(title.begin(), title.end());
    return title;
  }
};

int main() {

  return 0;
}
