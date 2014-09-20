#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 500
const int INF = 0x3f3f3f3f;

typedef long long ll;

ll f[MAXN + 1];
int c[MAXN + 1], b[MAXN + 1], w[MAXN + 1];
int n, k;

inline int unhappiness_between(int i, int j) {
    return (b[j] - b[i]) * (w[j] - w[i]);
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
        b[i] = b[i - 1] + c[i];
        w[i] = w[i - 1] + (c[i] ^ 1);
    }
    fill(f, f + MAXN + 1, INF);

    for (int i = 1; i <= n; ++i) {
        f[i] = unhappiness_between(0, i);
    }

    for (int _k = 2; _k <= k; ++_k) {
        for (int _n = n; _n >= _k; --_n) {
            f[_n] = INF;
            for (int i = 1; i < _n; ++i) {
                f[_n] = min(f[_n], f[_n - i] + unhappiness_between(_n - i, _n));
            }
        }
    }
    printf("%lld\n", f[n]);

    return 0;
}
