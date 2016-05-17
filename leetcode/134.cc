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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<int> d;
    int n = gas.size();
    for (int i = 0; i < n; ++i) {
      d.push_back(gas[i] - cost[i]);
    }
    for (int i = 0; i < n; ++i) {
      d.push_back(d[i]);
    }
    int p = 0, sum = 0;
    for (int i = 0; i < (n << 1); ++i) {
      if (sum >= 0) {
        sum += d[i];
        if (i - p == n) {
          return p;
        }
      } else {
        sum = d[i];
        p = i;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> gas = { 3, 4 };
  vector<int> cost = { 3, 4 };
  printf("%d\n", s.canCompleteCircuit(gas, cost));
  return 0;
}
