#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 205;
const int M = 25;
const int D = 45;
const int INF = 0x3f3f3f3f;

struct Node {
  int n, m, d;
  bool f;
};

short f[N][M][D], fs[N][M][D];
Node parent[N][M][D];

int p[N];
int d[N];
int dif[N];
int sum[N];

int main() {
  int n, m, n_case = 1;
  while (scanf("%d %d", &n, &m), n && m) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", p + i, d + i);
      dif[i] = p[i] - d[i];
      sum[i] = p[i] + d[i];
    }

    // clean
    for (int k = 0; k < D; ++k) {
      f[0][0][k] = fs[0][0][k] = 0;
    }
    //fill_n(f[0][0], N * M * D, 0);
    //fill_n(fs[0][0], N * M * D, 0);
    //fill_n(parent[0][0], N * M * D, -1);
    
    // initial set up
    for (int i = 1; i <= min(n, m); ++i) {
      for (int k = 0; k < D; ++k) {
        f[i][i][k] = dif[i] + f[i - 1][i - 1][k];
        fs[i][i][k] = sum[i] + fs[i - 1][i - 1][k];
        parent[i][i][k] = (Node) { i - 1, i - 1, k, true };
      }
    }
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < min(i, m + 1); ++j) {
        // [0, 45] => [-20, 20]
        for (int k = 0; k < D; ++k) {
          f[i][j][k] = f[i - 1][j][k];
          fs[i][j][k] = fs[i - 1][j][k];
          parent[i][j][k] = (Node) { i - 1, j, k, false };
          for (int kk = 0; kk < D; ++kk) {
            int x = abs(f[i - 1][j - 1][kk] + dif[i] - (k - 20));
            int y = abs(f[i][j][k] - (k - 20));
            int z = fs[i - 1][j - 1][kk] + sum[i];
            if (x < y || (x == y && fs[i][j][k] < z)) {
              f[i][j][k] = f[i - 1][j - 1][kk] + dif[i];
              fs[i][j][k] = z;
              parent[i][j][k] = (Node) { i - 1, j - 1, kk, true };
            }
          }
        }
      }
    }
    //printf("%d\n", f[n][m][20]);
    //printf("%d\n", fs[n][m][20]);
    vector<int> jurys;
    Node ptr = parent[n][m][20];
    if (ptr.f) {
      jurys.push_back(ptr.n + 1);
    }
    while (ptr.n) {
      ptr = parent[ptr.n][ptr.m][ptr.d];
      if (ptr.f) {
        jurys.push_back(ptr.n + 1);
      }
    }
    int sump = 0;
    int sumd = 0;
    for (int i = 0; i < m; ++i) {
      sump += p[jurys[i]];
      sumd += d[jurys[i]];
    }
    printf("Jury #%d\n", n_case++);
    printf("Best jury has value %d for prosecution and value %d for defence:\n", sump, sumd);
    for (int i = m - 1; i >= 0; --i) {
      printf(" %d", jurys[i]);
    }
    printf("\n");
  }
  return 0;
}
