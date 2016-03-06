#include <iostream>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string ret;
    int n = s.size();
    int p = 2 * numRows - 2;
    int numCols = n / p * 2 + (n % p > 0) + (n % p > numRows);
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < numCols; ++j) {
        if ((j & 1) && (i == 0 || i == numRows - 1)) {
          continue;
        }
        int x = j / 2 * p;
        if (j & 1) {
          x += (numRows << 1) - i - 2;
        } else {
          x += i;
        }
        if (x < n) {
          ret += s[x];
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  cout << s.convert("PAYPALISHIRING", 3) << endl;
  cout << s.convert("PAYPALISHIRING", 4) << endl;
  cout << s.convert("ABCD", 3) << endl;
  return 0;
}
