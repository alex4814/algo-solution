#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    string ret;
    for (int i = 0; i < n; ++i) {
      int x = 1;
      while (i - x >= 0 && i + x < n) {
        if (s[i - x] != s[i + x]) {
          break;
        }
        x += 1;
      }
      x -= 1;
      if (2 * x + 1 > ret.size()) {
        ret = s.substr(i - x, 2 * x + 1);
      }
    }
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] != s[i + 1]) {
        continue;
      }
      int x = 1;
      while (i - x >= 0 && i + 1 + x < n) {
        if (s[i - x] != s[i + 1 + x]) {
          break;
        }
        x += 1;
      }
      x -= 1;
      if (2 * x + 2 > ret.size()) {
        ret = s.substr(i - x, 2 * x + 2);
      }
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  cout << s.longestPalindrome("abcba") << endl;
  cout << s.longestPalindrome("adfadkxkfjaka") << endl;
  return 0;
}
