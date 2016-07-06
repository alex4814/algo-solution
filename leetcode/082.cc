/*
 * Creation Date: 2016-07-02
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p = nullptr;
    ListNode *q = head;
    while (q) {
      bool dup = false;
      while (q->next && q->next->val == q->val) {
        dup = true;
        q = q->next;
      }
      if (dup && p == nullptr) {
        q = head = q->next;
      } else if (dup) {
        q = p->next = q->next;
      } else {
        p = q;
        q = q->next;
      }
    }
    return head;
  }
};

int main() {

  return 0;
}
