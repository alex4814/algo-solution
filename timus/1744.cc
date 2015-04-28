#include <cstdio>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    printf("%d\n", n * (n - 1) / 2);
    for (int i = 1; i <= n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d %d %d\n", j + 1, (j + i) % n + 1, (j + i + i) % n + 1);
        }
    }

    return 0;
}
