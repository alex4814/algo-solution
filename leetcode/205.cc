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

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    int n = s.size();
    char mappings[256] = { 0 };
    bool mapped[256] = { false };
    for (int i = 0; i < n; ++i) {
      if (mappings[s[i]] == 0) {
        if (mapped[t[i]]) {
          return false;
        }
        mappings[s[i]] = t[i];
        mapped[t[i]] = true;
      } else if (mappings[s[i]] != t[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {

  return 0;
}

