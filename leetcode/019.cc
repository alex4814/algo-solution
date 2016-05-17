/*
 * Creation Date: 2016-04-17
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head;
    ListNode *a = nullptr, *b = head;
    while (--n) {
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      a = b;
      b = b->next;
    }
    if (b == head) {
      head = head->next;
    } else {
      a->next = b->next;
    }
    delete b;
    return head;
  }
};

int main() {

  return 0;
}
