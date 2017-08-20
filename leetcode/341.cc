/*
 * Creation Date: 2016-10-07
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
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    insert(nestedList);
  }
  int next() {
    auto it_tail = it_stack.back();
    auto ret = it_tail->getInteger();
    advance();
    return ret;
  }
  bool hasNext() {
    return !it_stack.empty();
  }
private:
  void insert(vector<NestedInteger> &li) {
    auto it = li.begin();
    if (it != li.end()) {
      it_stack.push_back(it);
      li_stack.push_back(&li);
      if (!it->isInteger()) {
        insert(it->getList());
      }
    } else {
      advance();
    }
  }
  void advance() {
    if (!it_stack.empty()) {
      ++it_stack.back();
      modify();
    }
  }
  void modify() {
    if (!it_stack.empty()) {
      auto it_tail = it_stack.back();
      auto li_tail = li_stack.back();
      if (it_tail == li_tail->end()) {
        it_stack.pop_back();
        li_stack.pop_back();
        advance();
      } else if (!it_tail->isInteger()) {
        insert(it_tail->getList());
      }
    }
  }
  vector<vector<NestedInteger>::iterator> it_stack;
  vector<const vector<NestedInteger>*> li_stack;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
  return 0;
}
