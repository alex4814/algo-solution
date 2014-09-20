/*
ID: alex4814
PROG: barn1
LANG: C++
*/

//#define NDEBUG
#define FILEIO

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 205
#define EPS 1e-8
#define INF 0x3f3f3f3f

int m, s, c;
int n[MAXN], d[MAXN];

int main() {

#ifdef FILEIO
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
#endif

    scanf("%d %d %d", &m, &s, &c);
    for (int i = 0; i < c; ++i) {
        scanf("%d", &n[i]);
    }
    sort(n, n + c);

    int k = 0;
    for (int i = 1; i < c; ++i) {
        d[k++] = n[i] - n[i - 1] - 1;
    }
    sort(d, d + k);

    int ret = n[c - 1] - n[0] + 1;
    for (int i = 1; i < min(m, k + 1); ++i) {
        ret -= d[k - i];
    }
    printf("%d\n", ret);

    return 0;
}
