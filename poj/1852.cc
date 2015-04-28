#include <cstdio>
#include <algorithm>
using namespace std;

int T;
int n, length;
int earliest, latest;

int main() {
    scanf("%d", &T);
    while (T--) {
        earliest = latest = 0;

        scanf("%d %d", &length, &n);
        for (int i = 0, v; i < n; ++i) {
            scanf("%d", &v);
            earliest = max(earliest, min(v, length - v));
            latest = max(latest, max(v, length - v));
        }

        printf("%d %d\n", earliest, latest);
    }
    return 0;
}
