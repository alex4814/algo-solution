#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<int> path;
  void dfs(int ix, int n, int pos, vector<string> &p) {
    path.push_back(pos);
    if (ix == n) {
      string r(2 * n, ')');
      int sz = path.size();
      for (int i = 0; i < sz; ++i) {
        r[path[i]] = '(';
      }
      p.push_back(r);
      path.pop_back();
      return;
    }
    for (int i = pos + 1; i < 2 * ix + 1; ++i) {
      dfs(ix + 1, n, i, p);
    }
    path.pop_back();
  }
  vector<string> generateParenthesis(int n) {
    vector<string> p;
    if (n <= 0) {
      return p;
    }
    dfs(1, n, 0, p);
    return p;
  }
};

int main() {
  Solution s = Solution();
  vector<string> p = s.generateParenthesis(3);
  for (string s: p) {
    cout << s << endl;
  }
  return 0;
}
