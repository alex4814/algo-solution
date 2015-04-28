#include <cstdio>
using namespace std;

#define MAXN 44

typedef long long ll;

ll f[MAXN][2];
int n, k;

int main() {
    scanf("%d %d", &n, &k);

    f[1][0] = f[1][1] = 1;
    for (int len = 2; len <= n; ++len) {
        f[len][0] = f[len - 1][0] + f[len - 1][1];
        f[len][1] = f[len - 1][0];
    }

    if (k > f[n][0] + f[n][1]) {
        printf("-1\n");
    } else {
        for (int i = n; i > 0; --i) {
            printf(k <= f[i][0] ? "0" : (k -= f[i][0], "1"));
        }
        printf("\n");
    }
    return 0;
}
