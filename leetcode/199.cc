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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    depthSearch(root, 1, ret);
    return ret;
  }
  void depthSearch(TreeNode *root, int lvl, vector<int> &ret) {
    if (root == nullptr) {
      return;
    }
    if (ret.size() < lvl) {
      ret.push_back(root->val);
    }
    depthSearch(root->right, lvl + 1, ret);
    depthSearch(root->left, lvl + 1, ret);
  }
};

int main() {

  return 0;
}
