#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    int l = 1, p = 0, x = 1;
    for (int i = 1; i < n; ++i) {
      if (i - x - 1 >= 0 && s[i - x - 1] == s[i]) {
        x += 2;
      } else if (s[i - 1] == s[i]) {
        x = 2;
      } else {
        x = 1;
      }
      if (x > l) {
        p = i + 1 - x;
        l = x;
      }
    }
    return s.substr(p, l);
  }
};

int main() {
  Solution s = Solution();
  cout << abc << endl;
  cout << s.longestPalindrome("abcba") << endl;
  cout << s.longestPalindrome("adff") << endl;
  cout << s.longestPalindrome("bbaabb") << endl;
  cout << s.longestPalindrome("bananas") << endl;
  return 0;
}
