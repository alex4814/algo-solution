class Solution {
public:
  int lengthOfLastWord(string s) {
    int n = s.size(), i = n - 1;
    while (i >= 0 && isspace(s[i])) --i;
    int cnt = 0;
    while (i >= 0) {
      if (isspace(s[i--])) break;
      ++cnt;
    }
    return cnt;
  }
};
