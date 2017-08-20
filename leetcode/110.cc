/*
 * Creation Date: 2016-08-17
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
  bool isBalanced(TreeNode* root) {
    bool balance = false;
    helper(root, balance);
    return balance;
  }
  int helper(TreeNode* root, bool &balance) {
    if (root == nullptr) {
      balance = true;
      return 0;
    }
    bool lb = false;
    bool rb = false;
    int lh = helper(root->left, lb);
    int rh = helper(root->right, rb);
    if (lb && rb && abs(lh - rh) <= 1) {
      balance = true;
    }
    return max(lh, rh) + 1;
  }
};

int main() {

  return 0;
}
