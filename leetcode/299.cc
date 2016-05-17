/*
 * Creation Date: 2016-05-17
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
  string getHint(string secret, string guess) {
    int c1[10] = { 0 };
    int c2[10] = { 0 };
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        ++bulls;
      } else {
        ++c1[secret[i] - '0'];
        ++c2[guess[i] - '0'];
      }
    }
    for (int i = 0; i < 10; ++i) {
      int x = min(c1[i], c2[i]);
      cows += x > 0 ? x : 0;
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};

int main() {

  return 0;
}
