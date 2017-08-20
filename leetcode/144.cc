/*
 * Creation Date: 2016-07-08
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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    preorder(root, ret);
    return ret;
  }
  void preorder(TreeNode *root, vector<int> &ret) {
    if (root == nullptr) {
      return;
    }
    ret.push_back(root->val);
    preorder(root->left, ret);
    preorder(root->right, ret);
  }
};

int main() {

  return 0;
}
