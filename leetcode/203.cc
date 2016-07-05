#include <cstdio>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *q = NULL;
    ListNode *p = head;
    ListNode *r = head;
    while (p) {
      if (p->val == val) {
        if (p == r) {
          r = p->next;
          p = r;
        } else {
          q->next = p->next;
          p = p->next;
        }
      } else {
        q = p;
        p = p->next;
      }
    }
    return r;
  }
};

int main() {
  return 0;
}
