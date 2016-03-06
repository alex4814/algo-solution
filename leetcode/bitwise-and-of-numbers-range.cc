#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int x = m ^ n;
    if (!x) {
      return m;
    }
    int y = 0;
    while (x >>= 1) {
      y += 1;
    }
    y += 1;
    return (m >> y) << y;
  }
};

int main() {
  int y = 1;
  while (y >>= 1) {
    printf("1");
  }
  Solution s = Solution();
  cout << s.rangeBitwiseAnd(5, 7) << endl;
  cout << s.rangeBitwiseAnd(2, 2) << endl;
  cout << s.rangeBitwiseAnd(2, 2000) << endl;
  return 0;
}

