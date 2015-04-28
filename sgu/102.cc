#include <cstdio>
using namespace std;

#define MAXN 10000

int euler(int n) {
    int ret = 1;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            n /= i, ret *= i - 1;
            while (n % i == 0) {
                n /= i, ret *= i;
            }
        }
    }
    return ret * (n > 1 ? n - 1 : 1);
}

int n;

int main() {
    scanf("%d", &n);
    printf("%d\n", euler(n));
    return 0;
}
