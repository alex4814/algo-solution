#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    const int INF = 0x3f3f3f3f;
    int len = INF;
    int n = strs.size();
    if (!n) {
      return "";
    }
    for (int i = 0; i < n; ++i) {
      len = min(len, (int)strs[i].size());
    }
    string ret;
    for (int ix = 0; ix < len; ++ix) {
      bool allsame = true;
      char c = strs[0][ix];
      for (int i = 1; i < n; ++i) {
        if (strs[i][ix] != c) {
          allsame = false;
          break;
        }
      } 
      if (allsame) {
        ret += c;
      } else {
        break;
      }
    }
    return ret;
  }
};

int main() {

  return 0;
}
