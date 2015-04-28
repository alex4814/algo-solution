#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 60000
const int INF = 0x3f3f3f3f;

vector<int> lands;
int f[MAXN + 1];
int n, m;

int main() {
    for (int i = 1; i * i <= MAXN; ++i) {
        lands.push_back(i * i);
    }
    m = (int)lands.size();
    for (int i = 1; i <= MAXN; ++i) {
        f[i] = INF;
    }

    scanf("%d", &n);
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - lands[j] < 0) break;
            f[i] = min(f[i], f[i - lands[j]] + 1);
        }
    }
    printf("%d\n", f[n]);

    return 0;
}
