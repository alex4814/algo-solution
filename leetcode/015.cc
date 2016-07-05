#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(); 
    vector<vector<int>> ret;
    for (int i = 0; i < n; ++i) {
      if (i && nums[i] == nums[i - 1]) {
        continue;
      }
      bool b = false;
      for (int j = i + 2; j < n; ++j) {
        if (j > i + 2 && b && nums[j] == nums[j - 1]) {
          continue;
        }
        int x = 0 - nums[i] - nums[j];
        if (x < nums[i] || nums[j] < x) {
          continue;
        }
        if (!binary_search(nums.begin() + i + 1, nums.begin() + j, x)) {
          b = false;
          continue;
        }
        vector<int> item = { nums[i], x, nums[j] };
        ret.push_back(item);
        b = true;
      }
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  vector<int> f = { -1, 0, 1, 2, -1, -4 };
  auto x = s.threeSum(f);
  /*
  for (auto aa : x) {
    for (auto bb : aa) {
      printf("%d\n", bb);
    }
  }
  */
  return 0;
}
