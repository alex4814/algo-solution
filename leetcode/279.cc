#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> squares;
    for (int i = 1; i * i <= n; ++i) {
      squares.push_back(i * i);
    }
    int *f = new int[n + 1];
    for (int i = 0; i < 4; ++i) {
      f[i] = i;
    }
    for (int i = 4; i <= n; ++i) {
      f[i] = INT_MAX;
      for (int j = 0; j < squares.size() && squares[j] <= i; ++j) {
        f[i] = min(f[i], f[i - squares[j]] + 1);
      }
    }
    int x = f[n];
    delete[] f;
    return x;
  }
};

int main() {
  Solution s = Solution();
  s.numSquares(6);
  return 0;
}
