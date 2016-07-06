/*
 * Creation Date: 2016-06-11
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


// Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (root == NULL) {
      return;
    }
    auto p = root;
    while (p->left) {
      auto q = p;
      while (q) {
        q->left->next = q->right;
        q->right->next = q->next ? q->next->left : NULL;
        q = q->next;
      }
      p = p->left;
    }
  }
};

int main() {

  return 0;
}
