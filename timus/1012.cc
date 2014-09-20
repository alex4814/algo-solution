#include <cstdio>
using namespace std;

#define MAX_LENS 178
#define MAX_BASE 10

typedef long long ll;

ll f[MAX_LENS + 1][MAX_BASE];
int n, k;

int main() {
    for (int i = 0; i < MAX_BASE; ++i) {
        f[1][i] = 1;
    }

    scanf("%d %d", &n, &k);
    for (int len = 2; len <= n; ++len) {
        for (int d = 0; d < k; ++d) {
            for (int _d = 0; _d < k; ++_d) {
                if (len - 1 == 1 && _d == 0) continue;
                if (d == 0 && _d == 0) continue;
                f[len][d] += f[len - 1][_d];
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += f[n][i];
    }
    printf("%lld\n", sum);

    return 0;
}
