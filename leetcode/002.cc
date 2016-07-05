#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = NULL, *p, *node;
    int c = 0, x;
    while (l1 && l2) {
      x = l1->val + l2->val + c;
      node = new ListNode(x % 10);
      c = x / 10;
      if (head == NULL) {
        head = p = node;
      } else {
        p->next = node;
        p = node;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1) {
      x = l1->val + c;
      node = new ListNode(x % 10);
      c = x / 10;
      if (head == NULL) {
        head = p = node;
      } else {
        p->next = node;
        p = node;
      }
      l1 = l1->next;
    }
    while (l2) {
      x = l2->val + c;
      node = new ListNode(x % 10);
      c = x / 10;
      if (head == NULL) {
        head = p = node;
      } else {
        p->next = node;
        p = node;
      }
      l2 = l2->next;
    }
    if (c) {
      node = new ListNode(c);
      p->next = node;
    }
    return head;
  }
};

