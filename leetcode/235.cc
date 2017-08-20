/*
 * Creation Date: 2016-07-11
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode *> pp, pq, path;
    pathTo(root, p, path, pp);
    pathTo(root, q, path, pq);
    int n = min(pp.size(), pq.size());
    TreeNode *lca = nullptr;
    for (int i = 0; i < n; ++i) {
      if (pp[i] != pq[i]) {
        break;
      }
      lca = pp[i];
    }
    return lca;
  }
  void pathTo(TreeNode *root, 
      TreeNode *p, 
      vector<TreeNode *> &path,
      vector<TreeNode *> &ret) {
    if (root == nullptr) {
      return;
    }
    path.push_back(root);
    if (root == p) {
      ret = path;
    }
    pathTo(root->left, p, path, ret);
    pathTo(root->right, p, path, ret);
    path.pop_back();
  }
};

int main() {

  return 0;
}
