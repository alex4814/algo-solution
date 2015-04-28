#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 500

typedef long long ll;

ll f[MAXN + 1][MAXN];
int n;

int main() {
    scanf("%d", &n);

    f[3][2] = f[4][3] = 1;
    for (int i = 1; i < n; ++i) {
        f[i][i] = 1;
    }

    for (int tot = 5; tot <= n; ++tot) {
        for (int e = 2; e < tot; ++e) {
            for (int _e = 1; _e < e; ++_e) {
                f[tot][e] += f[tot - e][_e];
            }
        }
    }

    ll sum = 0;
    for (int e = 2; e < n; ++e) {
        sum += f[n][e];
    }
    printf("%lld\n", sum);

    return 0;
}
