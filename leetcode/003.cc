#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    deque<int> d;
    vector<bool> isin(256, false);

    int ret = 0;
    for (const int c : s) {
      if (isin[c]) {
        while (!d.empty()) {
          int x = d.front();
          d.pop_front();
          if (x == c) {
            break;
          }
          isin[x] = false;
        }
      }
      d.push_back(c);
      isin[c] = true;
      if (d.size() > ret) {
        ret = d.size();
      }
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  cout << s.lengthOfLongestSubstring("abcdeaa") << endl;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << s.lengthOfLongestSubstring("bbbbb") << endl;
  cout << s.lengthOfLongestSubstring("") << endl;
  return 0;
}
