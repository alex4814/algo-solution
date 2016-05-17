#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    auto pt = make_pair(-1, 0);
    int n = nums.size(), step = 0;
    for (int i = 0; i < n; ++i) {
      if (pt.second + 1 >= n) break;
      if (i > pt.first) {
        swap(pt.first, pt.second);
        step += 1;
      }
      pt.second = max(pt.second, i + nums[i]);
    }
    return step;
  }
};

int main() {
  return 0;
}
