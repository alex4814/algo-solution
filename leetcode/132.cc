#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int minCut(string s) {
    int n = s.size();
    vector<int> *g = new vector<int>[n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; i - j >= 0 && i + j < n; ++j) {
        if (s[i - j] != s[i + j]) break;
        g[i + j].push_back(i - j);
      }
      if (i + 1 < n && s[i] != s[i + 1]) continue;
      for (int j = 0; i - j >= 0 && i + 1 + j < n; ++j) {
        if (s[i - j] != s[i + 1 + j]) break;
        g[i + 1 + j].push_back(i - j);
      }
    }
    vector<int> f(n + 1, INT_MAX);
    f[0] = -1; f[1] = 0;
    for (int i = 1; i < n; ++i) {
      // f[i + 1]
      for (int j = 0; j < g[i].size(); ++j) {
        int b = g[i][j];
        f[i + 1] = min(f[i + 1], f[b] + 1);
      }
    }
    delete[] g;
    return max(0, f[n]);
  }
};

int main() {
  return 0;
}
