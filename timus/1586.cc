#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 10000
#define MOD 1000000009

typedef long long ll;

ll f[MAXN + 1][10][10];
int n;

bool is_prime(int x) {
    if (x < 2) return false;

    int _n = sqrt(x);
    for (int i = 2; i <= _n; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);

    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10; ++i) {
            for (int k = 100 + i * 10 + j; k < 1000; k += 100) {
                if (is_prime(k)) {
                    ++f[3][i][j];
                }
            }
        }
    }

    for (int len = 4; len <= n; ++len) {
        for (int j = 0; j < 10; ++j) {
            for (int i = 0; i < 10; ++i) {
                for (int k = 1; k < 10; ++k) {
                    f[len][i][j] = (f[len][i][j] +
                        (is_prime(k * 100 + i * 10 + j) ? f[len - 1][k][i] : 0)) % MOD;
                }
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            sum = (sum + f[n][i][j]) % MOD;
        }
    }
    printf("%lld\n", sum);

    return 0;
}
