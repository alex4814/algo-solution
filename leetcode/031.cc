#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int ix = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        ix = i; break;
      }
    }
    if (ix == -1) {
      reverse(begin(nums), end(nums));
      return;
    }
    for (int i = nums.size() - 1; i > ix; --i) {
      if (nums[i] > nums[ix]) {
        swap(nums[i], nums[ix]);
        reverse(begin(nums) + ix + 1, end(nums));
        break;
      }
    }
  }
};


// 2 3 4 6 5 1
// 2 3 5 1 4 6
int main() {
  return 0;
}
