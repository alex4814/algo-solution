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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void numRec(TreeNode *rt, int &sum, int curSum = 0) {
    if (rt == NULL) {
      return;
    }
    curSum = curSum * 10 + rt->val;
    if (rt->left == NULL && rt->right == NULL) {
      sum += curSum;
    } else {
      numRec(rt->left, sum, curSum);
      numRec(rt->right, sum, curSum);
    }
  }
  int sumNumbers(TreeNode *root) {
    int sum = 0;
    numRec(root, sum); 
    return sum;
  }
};

int main() {

  return 0;
}

