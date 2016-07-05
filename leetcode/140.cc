#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<int> *g = new vector<int>[n];

    vector<string> ret;
    if (!n) return ret;
    for (int i = 0; i < n; ++i) {
      for (int j = -1; j < i; ++j) {
        if (g[j].size() == 0) continue;
        if (wordDict.find(s.substr(j + 1, i - j)) == wordDict.end()) continue;
        g[i].push_back(j);
      }
    }

    back_tracking(g, n - 1, s, ret);

    delete[] g;
    return ret;
  }
  void back_tracking(vector<int> g[], int ix, string s, vector<string> &ret) {
    static vector<int> path;
    for (int i = 0; i < g[ix].size(); ++i) {
      if (~g[ix][i]) {
        path.push_back(g[ix][i]);
        back_tracking(g, g[ix][i], s, ret);
        path.pop_back();
      } else {
        string sen;
        int n = path.size();
        int b = 0;
        for (int p = n - 1; p >= 0; --p) {
          sen += s.substr(b, path[p] + 1 - b) + " ";
          b = path[p] + 1;
        }
        sen += s.substr(b, s.size() - b);
        ret.push_back(sen);
      }
    }
  }
};

int main() {
  unordered_set<string> dict = { "cat","cats","and","sand","dog" };
  string s = "catsanddog";
  Solution sl = Solution();
  vector<string> ret = sl.wordBreak(s, dict);
  for (auto x: ret) {
    cout << x << endl;
  }
  return 0;
}
