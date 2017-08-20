/*
 * Creation Date: 2016-08-18
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret;
    levelOrder(root, 0, ret);
    reverse(ret.begin(), ret.end());
    return ret;
  }
  void levelOrder(TreeNode *root, int lvl, vector<vector<int>> &ret) {
    if (root == nullptr) {
      return;
    }
    if (ret.size() <= lvl) {
      ret.push_back(vector<int>());
    }
    ret[lvl].push_back(root->val);
    levelOrder(root->left, lvl + 1, ret);
    levelOrder(root->right, lvl + 1, ret);
  }
};

int main() {

  return 0;
}
