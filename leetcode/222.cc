/*
 * Creation Date: 2016-04-26
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
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};

class Solution {
public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr) {
      return 1;
    }
    TreeNode *p = root;
    int h = 0;
    while (p = p->left) {
      h += 1;
    }
    int lo = 1 << h - 1;
    int hi = 1 << h;
    while (lo < hi) {
      int mid = lo + (hi - lo >> 1);
      auto pk = kth_node(root, mid);
      if (pk->left && pk->right) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    if (hi == 1 << h) {
      return hi * 2 - 1;
    }
    auto pk = kth_node(root, hi);
    return pk->left ? 2 * hi : 2 * hi - 1;
  }
  TreeNode *kth_node(TreeNode *root, int k) {
    vector<int> s;
    while (k > 1) {
      s.push_back(k & 1);
      k >>= 1;
    }
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      root = *it ? root->right : root->left;
    }
    return root;
  }
};

class CBT {
public:
  CBT() = default;
  CBT(vector<int> nums): root(nullptr) {
    root = build(nums, 0, nums.size());
  }
  TreeNode *get_root() {
    return root;
  }
  ~CBT() {
    if (root) delete root;
  }
private:
  TreeNode *root;
  TreeNode *build(vector<int> nums, int s, int e) {
    if (s >= e) {
      return nullptr;
    }
    TreeNode *node = new TreeNode(nums[s]);
    node->left = build(nums, (s << 1) + 1, e);
    node->right = build(nums, (s << 1) + 2, e);
    return node;
  }
};

int main() {
  Solution s;
  vector<int> tn;
  for (int i = 0; i < 1532; ++i) {
    tn.push_back(i);
  }
  CBT cbt(tn);
  int cnt = s.countNodes(cbt.get_root());
  printf("%d\n", cnt);
  return 0;
}
