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
  bool hasCycle(ListNode *head) {
    ListNode *tail = head;
    while (head && tail && tail->next) {
      head = head->next;
      tail = tail->next->next;
      if (head && head == tail) return true;
    }
    return false;
  }
};

int main() {
  return 0;
}
