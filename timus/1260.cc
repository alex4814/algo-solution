#include <cstdio>
using namespace std;

#define MAXN 55

typedef long long ll;

ll f[MAXN + 1];
int n;

int main() {
    scanf("%d", &n);

    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    for (int i = 4; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 3] + 1;
    }
    printf("%lld\n", f[n]);
    return 0;
}
