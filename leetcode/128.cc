/*
 * Creation Date: 2016-07-19
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
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> forest;
    for (int n: nums) {
      if (forest.count(n) > 0) {
        continue;
      }
      forest[n] = n;
      if (forest.count(n + 1) > 0) {
        int p = n + 1;
        while (p != forest[p]) {
          p = forest[p];
        }
        int q = n;
        while (q != p) {
          forest[q] = p;
          q = forest[q];
        }
      }
      if (forest.count(n - 1) > 0) {
        forest[n - 1] = forest[n];
      }
    }
    int ret = 0;
    for (auto t: forest) {
      int p = t.second;
      while (forest[p] != p) {
        p = forest[p];
      }
      ret = max(ret, p - t.first + 1);
    }
    return ret;
  }
};

int main() {
  vector<int> nums = { 2, 4, 1, 55, 3, 54 };
  Solution s;
  printf("%d\n", s.longestConsecutive(nums));
  return 0;
}
