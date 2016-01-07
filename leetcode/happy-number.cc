#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

class Solution {
public:
  bool isHappy(int n) {
    set<int> history;
    while (n != 1) {
      n = generate(n);
      if (history.empty() == false && history.find(n) != history.end()) {
        return false;
      }
      history.insert(n);
    }
    return true;
  }
  int generate(int x) {
    int s = 0, n = 0;
    int d[10];
    while (x > 0) {
      d[n++] = x % 10;
      x /= 10;
    }
    for (int i = 0; i < n; ++i) {
      s += d[i] * d[i];
    }
    return s;
  }
};

int main() {
  Solution s = Solution();
  printf("%d\n", s.isHappy(19));
  printf("%d\n", s.isHappy(23030035));
  return 0;
}

