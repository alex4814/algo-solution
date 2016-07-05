#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    // new 
    int **f = new int*[n1 + 1];
    for (int i = 0; i <= n1; ++i) {
      f[i] = new int[n2 + 1];
    }
    // init
    for (int i = 0; i <= n1; ++i) {
      for (int j = 0; j <= n2; ++j) {
        f[i][j] = INT_MAX;
      }
    }

    f[0][0] = 0;
    for (int i = 0; i < n1; ++i) {
      f[i + 1][0] = i + 1;
    }
    for (int i = 0; i < n2; ++i) {
      f[0][i + 1] = i + 1;
    }
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        f[i][j] = min(f[i][j], f[i - 1][j] + 1);
        f[i][j] = min(f[i][j], f[i][j - 1] + 1);
        f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        if (word1[i - 1] == word2[j - 1]) {
          f[i][j] = min(f[i][j], f[i - 1][j - 1]);
        }
      }
    }

    int x = f[n1][n2];

    // delete
    for (int i = 0; i <= n1; ++i) {
      delete[] f[i];
    }
    delete[] f;

    return x;
  }
};

int main() {

  return 0;
}
