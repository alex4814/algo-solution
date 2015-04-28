#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 1000

bool diag[MAXN + 1][MAXN + 1];
double d[MAXN + 1][MAXN + 1];

int n, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0, x, y; i < k; ++i) {
        scanf("%d %d", &x, &y);
        diag[x][y] = true;
    }

    for (int j = 0; j <= m; ++j) {
        d[0][j] = j * 100.0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            d[i][j] = d[i - 1][j] + 100;
            if (j) { d[i][j] = min(d[i][j], d[i][j - 1] + 100); }
            if (diag[i][j]) { d[i][j] = min(d[i][j], d[i - 1][j - 1] + 100 * sqrt(2)); }
        }
    }
    printf("%.0f\n", d[n][m]);
    return 0;
}
