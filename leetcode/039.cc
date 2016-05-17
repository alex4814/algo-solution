#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(begin(candidates), end(candidates));
    auto it = unique(begin(candidates), end(candidates)); 
    candidates.resize(distance(begin(candidates), it));
    
    vector<vector<int>> ret;
    vector<int> comb;
    targetSum(0, candidates, target, comb, ret);
    return ret;
  }

  void targetSum(int ix, vector<int> &candidates, int target, vector<int> &comb, vector<vector<int>> &ret) {
    if (target == 0) {
      ret.push_back(comb);
      return;
    }
    for (int i = ix; i < candidates.size(); ++i) {
      if (candidates[i] > target) break;
      comb.push_back(candidates[i]);
      targetSum(i, candidates, target - candidates[i], comb, ret);
      comb.pop_back();
    }
  }
};

int main() {
  return 0;
}
