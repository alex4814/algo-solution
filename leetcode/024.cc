#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *p = head;
    ListNode *q = (p ? p->next : NULL);
    if (q) {
      head = q;
    }
    ListNode *t = NULL;
    while (p && q) {
      if (t) {
        t->next = q;
      }
      t = p;
      p->next = q->next;
      q->next = p;
      p = p->next;
      q = (p ? p->next : NULL);
    }
    return head;
  }
};

void print(ListNode *root) {
  ListNode *p = root;
  while (p) {
    if (p != root) {
      cout << ' ';
    }
    cout << p << '-' << p->val;
    p = p->next;
  }
  cout << endl;
}

ListNode *createList(int *a, int n) {
  ListNode *head = NULL;
  if (n > 0) {
    head = new ListNode(a[0]);
  }
  ListNode *p = head;
  for (int i = 1; i < n; ++i) {
    ListNode *node = new ListNode(a[i]);
    p->next = node;
    p = node;
  }
  return head;
}

int main() {
  int a[] = { 1, 2, 3, 4, 5 };
  ListNode* head = createList(a, 5);
  printf("\nhead\n");
  print(head);
  Solution s = Solution();
  ListNode *after = s.swapPairs(head);
  printf("\nafter\n");
  print(after);
  return 0;
}

