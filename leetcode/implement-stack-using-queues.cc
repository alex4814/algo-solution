#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

class Stack {
public:

  // Push element x onto stack.
  void push(int x) {
    stack.push_back(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    stack.pop_back();
  }

  // Get the top element.
  int top() {
    return stack.back();
  }

  // Return whether the stack is empty.
  bool empty() {
    return stack.empty();
  }

private:

  vector<int> stack;
};

int main() {
  Stack a;
  a.push(3);
  printf("%d\n", a.empty());
  printf("%d\n", a.top());
  a.push(45);
  printf("%d\n", a.top());
  a.pop();
  printf("%d\n", a.empty());
  return 0;
}

