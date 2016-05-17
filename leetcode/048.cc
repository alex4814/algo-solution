#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
      for (int j = i; j < n - 1 - i; ++j) {
        int ci = i, cj = j;
        for (int k = 0; k < 3; ++k) {
          int bi = n - 1 - cj;
          int bj = ci;
          swap(matrix[bi][bj], matrix[ci][cj]);
          ci = bi;
          cj = bj;
        }
      }
    }
  }
};

int main() {
  return 0;
}
