/*
 * Creation Date: 2016-07-17
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


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    return buildTreeHelper(preorder, 0, n, inorder, 0, n);
  }
  TreeNode *buildTreeHelper(vector<int> &preorder, int plo, int phi,
      vector<int> &inorder, int ilo, int ihi) {
    if (plo == phi) {
      return nullptr;
    }
    int root = preorder[plo];
    int k = -1;
    for (int i = ilo; k == -1 && i < ihi; ++i) {
      if (inorder[i] == root) {
        k = i;
      }
    }
    TreeNode *lch = buildTreeHelper(preorder, plo + 1, plo + 1 + k - ilo,
        inorder, ilo, k);
    TreeNode *rch = buildTreeHelper(preorder, plo + 1 + k - ilo, phi,
        inorder, k + 1, ihi);
    TreeNode *rt = new TreeNode(root);
    rt->left = lch;
    rt->right = rch;
    return rt;
  }
};

int main() {
  vector<int> p = { 1,2,3,4,6,5 };
  vector<int> i = { 2,1,4,6,3,5 };
  Solution s;
  auto rt = s.buildTree(p, i);
  return 0;
}
