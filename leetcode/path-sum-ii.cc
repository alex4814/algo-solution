#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void pathSumRec(TreeNode *rt, int sum, vector<vector<int> > &r, vector<int> &curPath) {
    if (rt == NULL) {
      return;
    }
    if (rt->left == NULL && rt->right == NULL && rt->val == sum) {
      curPath.push_back(rt->val);
      r.push_back(curPath);
      curPath.pop_back();
    } else {
      curPath.push_back(rt->val);
      int newSum = sum - rt->val;
      pathSumRec(rt->left, newSum, r, curPath);
      pathSumRec(rt->right, newSum, r, curPath);
      curPath.pop_back();
    }
  }
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > r;
    vector<int> path;
    pathSumRec(root, sum, r, path);
    return r;
  }
};

int main() {

  return 0;
}

