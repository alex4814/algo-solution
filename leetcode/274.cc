/*
 * Creation Date: 2016-07-24
 * Created By: alex4814
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int x = (citations[i] > n ? n : citations[i]);
      cnt[x] += 1;
    }
    int tot = 0;
    for (int i = n; i > 0; --i) {
      tot += cnt[i];
      if (tot >= i) {
        return i;
      }
    }
    return 0;
  }
};

int main() {
  vector<int> c = { 1, 2, 3, 4, 4, 4, 5 };
  Solution s;
  cout << s.hIndex(c) << endl;
  return 0;
}
