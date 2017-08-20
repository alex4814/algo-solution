/*
 * Creation Date: 2016-09-05
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

class Solution {
public:
  vector<vector<string>> partition(string s) {
    if (s.empty()) {
      return {};
    }
    vector<vector<string>> ret;
    vector<string> path;
    search(s, 0, path, ret);
    return ret;
  }

  void search(string &s, int pos, vector<string> &path, vector<vector<string>> &ret) {
    if (pos == s.size()) {
      ret.push_back(path);
      return;
    }
    for (int i = pos; i < s.size(); ++i) {
      if (is_palindrome(s, pos, i + 1)) {
        path.push_back(s.substr(pos, i - pos + 1));
        search(s, i + 1, path, ret);
        path.pop_back();
      }
    }
  }

  bool is_palindrome(string &s, int lo, int hi) {
    while (lo < hi) {
      if (s[lo++] != s[--hi]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  auto ret = s.partition("aab");
  return 0;
}
