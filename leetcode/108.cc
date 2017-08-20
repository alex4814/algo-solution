/*
 * Creation Date: 2016-10-14
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

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size());
  }
  TreeNode *helper(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) {
      return nullptr;
    }
    int mi = lo + ((hi - lo) >> 1);
    TreeNode *root = new TreeNode(nums[mi]);
    root->left = helper(nums, lo, mi);
    root->right = helper(nums, mi + 1, hi);
    return root;
  }
};

int main() {

  return 0;
}
