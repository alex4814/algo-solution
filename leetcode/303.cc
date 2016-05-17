#include <cstdio>

using namespace std;


class NumArray {
public:
  NumArray(vector<int> &nums) {
    sums.push_back(0);
    for (int i = 0; i < nums.size(); ++i) {
      sums.push_back(sums[i] + nums[i]);
    }
  }
  int sumRange(int i, int j) {
    if (i < 0 || j >= sums.size()) {
      return 0;
    }
    return sums[j + 1] - sums[i];
  }
private:
  vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main() {
  return 0;
}
