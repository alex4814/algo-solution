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
  int nthUglyNumber(int n) {
    int p[] = { 0, 0, 0 };
    vector<int> un(n);
    un[0] = 1;
    for (int i = 1; i < n; ++i) {
      int x = un[p[0]] * 2;
      int y = un[p[1]] * 3;
      int z = un[p[2]] * 5;
      int nun = min(x, min(y, z));
      un[i] = nun;
      if (x == nun) p[0]++;
      if (y == nun) p[1]++;
      if (z == nun) p[2]++;
    }
    return un.back();
  }
};

int main() {
  Solution s;
  cout << s.nthUglyNumber(1) << endl;
  cout << s.nthUglyNumber(2) << endl;
  cout << s.nthUglyNumber(3) << endl;
  cout << s.nthUglyNumber(10) << endl;
  return 0;
}
