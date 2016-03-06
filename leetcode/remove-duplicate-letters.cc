#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> cnt(26, 0);
    for (const char c: s) {
      cnt[c - 'a'] += 1;
    }

    vector<char> letters;
    vector<bool> exist(26, false);
    for (const char c: s) {
      cnt[c - 'a'] -= 1;
      if (exist[c - 'a']) {
        continue;
      }
      while (!letters.empty() && c < letters.back() && cnt[letters.back() - 'a'] > 0) {
        exist[letters.back() - 'a'] = false;
        letters.pop_back();
      }
      exist[c - 'a'] = true;
      letters.push_back(c);
    }
    return string(letters.begin(), letters.end());
  }
};

int main() {
  Solution s = Solution();
  cout << s.removeDuplicateLetters("bcabc") << endl;
  cout << s.removeDuplicateLetters("cbacdcbc") << endl;
  cout << s.removeDuplicateLetters("baab") << endl;
  cout << s.removeDuplicateLetters("ccacbaba") << endl;
  cout << s.removeDuplicateLetters("bbcaac") << endl;
  return 0;
}
