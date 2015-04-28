#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

class Solution {
public:
  bool isValid(string s) {
    vector<char> pStack;
    map<char, char> m;
    m['('] = ')';
    m['['] = ']';
    m['{'] = '}';
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(' || s[i] == '[' or s[i] == '{') {
        pStack.push_back(s[i]);
      } else if (pStack.empty() || s[i] != m[pStack.back()]) {
        return false;
      } else {
        pStack.pop_back();
      }
    }
    return pStack.empty();
  }
};

int main() {
  Solution s;
  printf("%d\n", s.isValid("()[][[{}]]{"));
  return 0;
}

