#include <cstdio>

using namespace std;

const int N = 105;

int b[N][N], p[N][N];
int len[N];
int num[N][N], den[N][N];
double ratio[N][N];

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", len + i);
      for (int j = 0; j < len[i]; ++j) {
        scanf("%d %d", &b[i][j], &p[i][j]);
      }
    }
    for (int i = 0; i < len[0]; ++i) {
      num[0][i] = b[0][i];
      den[0][i] = p[0][i];
      ratio[0][i] = (double) b[0][i] / p[0][i];
    }
  }
  return 0;
}
