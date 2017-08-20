/*
 * Creation Date: 2016-07-24
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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (!p || !q) {
      return false;
    } else if (p->val != q->val) {
      return false;
    } else {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }
};

int main() {

  return 0;
}
