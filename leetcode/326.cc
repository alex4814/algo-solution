#include <cstdio>
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    static const int x = 1162261467;
    if (n <= 0 || n > x) {
      return false;
    }
    return x / n * n == x;
  }
};

int main() {
  int r = 1;
  for (int i = 0; r > 0; ++i) {
    printf("3^%02d = %d, ", i, r);
    cout << bitset<32>(r).to_string() << endl;
    r *= 3;
  }
  return 0;
}
