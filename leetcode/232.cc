/*
 * Creation Date: 2016-07-11
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

class Queue {
public:
  // Push element x to the back of queue.
  void push(int x) {
    in.push_back(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    if (out.empty()) {
      transfer();
    }
    if (!out.empty()) {
      out.pop_back();
    }
  }

  // Get the front element.
  int peek(void) {
    if (out.empty()) {
      transfer();
    }
    return out.back();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return in.empty() && out.empty();
  }
private:
  void transfer() {
    while (!in.empty()) {
      out.push_back(in.back());
      in.pop_back();
    }
  }
  vector<int> in;
  vector<int> out;
};

int main() {

  return 0;
}
