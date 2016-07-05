#include <cstdio>

using namespace std;

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr;
    ListNode *cur = head;
    while (l1 && l2) {
      ListNode *&t = l1->val < l2->val ? l1 : l2;
      head ? cur->next = t, cur = t : head = cur = t;
      t = t->next;
    }
    if (l1) (head ? cur->next : head) = l1;
    if (l2) (head ? cur->next : head) = l2;
    return head;
  }
};

int main() {
  return 0;
}
