#include <cstdio>

class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    int *f = new int[2 * (n + 1)];
    f[0] = f[1] = 0;
    for (int i = 0; i < n; ++i) {
      int li = 2 * (i + 1);
      int ri = li + 1;
      f[li] = max(f[li - 2], f[li - 1]);
      f[ri] = f[li - 2] + nums[i];
    }
    int x = max(f[n << 1], f[n << 1 | 1]);
    delete[] f;
    return x;
  }
};

int main() {
  return 0;
}
