#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    int length = 0;
    ListNode* tail = tailNode(head, length);
    
    if (length == 0) {
      return head;
    }
    k %= length;
    if (k == 0) {
      return head;
    }
    
    k = length - k - 1;
    ListNode* p = head;
    while (k--) {
      p = p->next;
    }
    tail->next = head;
    head = p->next;
    p->next = NULL;
    return head;
  }
  inline ListNode* tailNode(ListNode* head, int& length) {
    length = 0;
    ListNode* tail = NULL;
    while (head != NULL) {
      tail = head;
      length += 1;
      head = head->next;
    }
    return tail;
  }
};

