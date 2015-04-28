#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100

int a[MAXN][MAXN];
int s[MAXN][MAXN];
int n;

inline int sum_between(int row, int c1, int c2) {
    return s[row][c2] - ((c1 == 0) ? 0 : s[row][c1 - 1]);
}

int main() {
    int ret = -127;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            ret = max(ret, a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        s[i][0] = a[i][0];
        for (int j = 1; j < n; ++j) {
            s[i][j] = s[i][j - 1] + a[i][j];
        }
    }

    for (int c1 = 0; c1 < n; ++c1) {
        for (int c2 = c1; c2 < n; ++c2) {
            int sum = 0;
            for (int r = 0; r < n; ++r) {
                sum += sum_between(r, c1, c2);
                if (sum < 0) {
                    sum = 0;
                } else {
                    ret = max(ret, sum);
                }
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}
