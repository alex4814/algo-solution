#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) {
        return m;
      }
      nums[m] < target ? l = m + 1 : r = m;
    }
    return l; 
  }
};

int main() {
  vector<int> nums = { 1, 3, 5, 6 };
  Solution s = Solution();
  cout << s.searchInsert(nums, 5) << endl;
  cout << s.searchInsert(nums, 2) << endl;
  cout << s.searchInsert(nums, 7) << endl;
  cout << s.searchInsert(nums, 0) << endl;
  return 0;
}
