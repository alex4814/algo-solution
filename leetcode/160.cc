/*
 * Creation Date: 2016-05-15
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


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = getListLength(headA);
    int lenB = getListLength(headB);
    if (lenA < lenB) {
      swap(headA, headB);
      swap(lenA, lenB);
    }
    int k = lenA - lenB;
    while (k--) {
      headA = headA->next;
    }
    while (headA && headB) {
      if (headA == headB) {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return nullptr;
  }
  int getListLength(ListNode *head) {
    int len = 0;
    while (head) {
      head = head->next;
      ++len;
    }
    return len;
  }
};

int main() {

  return 0;
}
