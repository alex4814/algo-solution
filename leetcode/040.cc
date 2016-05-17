#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ret;
    auto it = candidates.begin();
    while (it != candidates.end()) {
      int x = *it;
      printf("x = %d\n", x);
      vector<vector<int>> res = combinationSum(candidates, ++it, target - x);
      for (auto vec: res) {
        vector<int> r = { x };
        r.insert(end(r), begin(vec), end(vec));
        ret.push_back(r);
      }
    }
    return ret;
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, vector<int>::iterator it, int target) {
    vector<vector<int>> ret;
    if (target <= 0 || it == candidates.end()) {
      return ret;
    }
    if (*it > target) {
      return ret;
    }
    if (*it == target) {
      vector<int> t{*it};
      ret.push_back(t);
      return ret;
    }
    while (it != candidates.end()) {
      int x = *it;
      vector<vector<int>> res = combinationSum(candidates, ++it, target - x);
      for (auto vec: res) {
        vector<int> r = { x };
        r.insert(end(r), begin(vec), end(vec));
        ret.push_back(r);
      }
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  vector<int> c = {10,1,2,7,6,1,5};
  int target = 8;
  auto ret = s.combinationSum2(c, target);
  for (auto vec: ret) {
    int n = vec.size();
    for (int i = 0; i < n; ++i) {
      printf("%d%c", vec[i], i + 1 == n ? '\n' : ' ');
    }
  }
  return 0;
}
