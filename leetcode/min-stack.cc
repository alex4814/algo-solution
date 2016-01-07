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

class MinStack {
public:
  vector<int> stack;
  vector<int> curMin;
  void push(int x) {
    stack.push_back(x);
    if (curMin.empty()) {
      curMin.push_back(x);
    } else {
      int y = curMin.back();
      curMin.push_back(min(x, y));
    }
  }
  void pop() {
    stack.pop_back();
    curMin.pop_back();
  }
  int top() {
    return stack.back();
  }
  int getMin() {
    return curMin.back();
  }
};

int main() {
  return 0;
}

