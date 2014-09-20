#include <cstdio>
using namespace std;

typedef long long ll;
#define MAXN 45

ll f[MAXN + 1][3];
int n;

int main() {
    scanf("%d", &n);
    f[1][0] = 0, f[1][1] = f[1][2] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i][0] = f[i - 1][1] + f[i - 1][2];
        f[i][1] = f[i - 1][2] + f[i - 1][0] - f[i - 2][2];
        f[i][2] = f[i - 1][1] + f[i - 1][0] - f[i - 2][1];
    }
    printf("%lld\n", f[n][1] + f[n][2]);
    return 0;
}
