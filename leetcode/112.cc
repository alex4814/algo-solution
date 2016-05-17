#include <cstdio>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) {
      return false;
    }
    if (root->val == sum && !root->left && !root->right) {
      return true;
    }
    int x = sum - root->val;
    return hasPathSum(root->left, x) || hasPathSum(root->right, x);
  }
};


int main() {
  return 0;
}
