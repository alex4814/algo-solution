#include <cstdio>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    return buildTree(inorder, postorder, 0, n, 0, n);
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int li, int ri, int lp, int rp) {
    if (li >= ri) {
      return NULL;
    }
    int val = postorder[rp - 1];
    TreeNode* rt = new TreeNode(val);
    int split = -1;
    for (int i = li; i < ri; ++i) {
      if (inorder[i] == val) {
        split = i; break;
      }
    }
    rt->left = buildTree(inorder, postorder, li, split, lp, lp + split - li);
    rt->right = buildTree(inorder, postorder, split + 1, ri, lp + split - li, rp - 1);
    return rt;
  }
};

int main() {
  return 0;
}
