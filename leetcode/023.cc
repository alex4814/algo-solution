/*
 * Creation Date: 2016-04-18
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
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *head = nullptr;
    ListNode *cur = head;

    priority_queue<ListNode*, vector<ListNode*>, Compare> q;
    for (const auto h: lists) {
      if (h == nullptr) continue;
      q.push(h);
    }
    while (!q.empty()) {
      auto t = q.top();
      q.pop();
      if (head) {
        cur = cur->next = t;
      } else {
        head = cur = t;
      }
      if (t->next) {
        q.push(t->next);
      }
    }
    return head;
  }
private:
  struct Compare {
    bool operator() (const ListNode *a, const ListNode *b) {
      return a->val > b->val;
    }
  };
};

int main() {

  return 0;
}
