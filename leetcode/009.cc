#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int len = log10(x);
    int n = 1;
    for (int i = 0; i < len; ++i) {
      n *= 10;
    }
    while (x > 0 && len > 0) {
      int e = log10(x);
      if (e == len && x / n != x % 10) {
        return false;
      }
      if (e < len && 0 != x % 10) {
        return false;
      }
      x = (x - x / n * n) / 10;
      len -= 2;
      n /= 100;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome(232) << endl;
  cout << s.isPalindrome(1000021) << endl;
  cout << s.isPalindrome(101) << endl;
  cout << s.isPalindrome(1001) << endl;
  cout << s.isPalindrome(1004400001) << endl;
  return 0;
}
