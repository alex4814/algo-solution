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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    vector<TreeNode *> stack;
    while (root || !stack.empty()) {
      if (root) {
        stack.push_back(root);
        root = root->left;
      } else {
        auto x = stack.back();
        stack.pop_back();
        ret.push_back(x->val);
        root = x->right;
      }
    }
    return ret;
  }
};

int main() {

  return 0;
}
