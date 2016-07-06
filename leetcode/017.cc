#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> ret;
    string curr;
    dfs(digits, 0, curr, ret);
    return ret;
  }
  void dfs(string digits, int i, string &curr, vector<string> &ret) {
    static const vector<string> mappings = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    if (i == digits.size()) {
      if (i > 0) {
        ret.push_back(curr);
      }
      return;
    }
    for (const char c: mappings[digits[i] - '0']) {
      curr.push_back(c);
      dfs(digits, i + 1, curr, ret);
      curr.pop_back();
    }
  }
};

int main() {
  Solution s;
  auto x = s.letterCombinations("23");
  for (auto str: x) {
    cout << str << endl;
  }
  return 0;
}
