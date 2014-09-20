/*
ID: alex4814
PROG: crypt1
LANG: C++
*/

#define NDEBUG
#define FILEIO

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 20
#define EPS 1e-8
#define INF 0x3f3f3f3f

int n;
bool in[MAXN] = { false };

bool valid(int x) {
    while (x > 0) {
        if (!in[x % 10]) return false;
        x /= 10;
    }
    return true;
}

int main() {
#ifdef FILEIO
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0, a; i < n; ++i) {
        scanf("%d", &a);
        in[a] = true;
    }

    int ret = 0;
    for (int x = 100; x < 1000; ++x) {
        for (int y = 10; y < 100; ++y) {
            if (!valid(x) || !valid(y)) continue;
            int p1 = y % 10 * x;
            int p2 = y / 10 * x;
            int p = y * x;
            if (p1 > 999 || p2 > 999 || p > 9999) continue;
            if (!valid(p1) || !valid(p2) || !valid(p)) continue;
            ++ret;
        }
    }
    printf("%d\n", ret);

    return 0;
}
