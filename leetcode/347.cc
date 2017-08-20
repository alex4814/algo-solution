/*
 * Creation Date: 2016-10-16
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
#include <unordered_map>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (const auto x : nums) {
      count[x] += 1;
    }
    int n = nums.size();
    vector<int> *buckets = new vector<int>[n + 1];
    for (const auto &p : count) {
      buckets[n - p.second].push_back(p.first);
    }
    vector<int> ret;
    for (int i = 0; i <= n; ++i) {
      ret.insert(ret.end(), buckets[i].begin(), buckets[i].end());
      if (ret.size() == k) {
        break;
      }
    }
    delete[] buckets;
    return ret;
  }
};

int main() {
  Solution s;
  vector<int> a { 1, 1, 1, 2, 2, 3 };
  auto ret = s.topKFrequent(a, 2);
  return 0;
}
