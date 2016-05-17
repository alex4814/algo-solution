#include <cstdio>

class Solution {
public:
  int singleNumber(int A[], int n) {
    for (int i = 1; i < n; ++i) {
      A[0] = A[0] ^ A[i];
    }
    return A[0];
  }
};

int A[] = { 1, 1, 6, 6, 9 };

int main() {
  Solution s;
  int r = s.singleNumber(A, 5);
  printf("%d\n", r);
  return 0;
}
