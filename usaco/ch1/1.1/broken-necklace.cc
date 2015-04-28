/*
ID: alex4814
PROG: beads
LANG: C++
*/

#define NDEBUG
#define FILEIO

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 705
#define EPS 1e-8

int n;
char s[MAXN];

int main() {
#ifdef FILEIO
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
#endif

    scanf("%d %s", &n, s);
    for (int i = n; i < n * 2; ++i) {
        s[i] = s[i - n];
    }
    s[n * 2] = '\0';

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = 0, k;
        // [x, i - 1]
        k = i - 1;
        while (k >= 0 && s[k] == 'w') { ++l, --k; }
        for (int j = k; j >= 0; --j) {
            if (s[j] != 'w' && s[j] != s[k]) break;
            ++l;
        }
        // [i, y]
        k = i;
        while (k < n * 2 && s[k] == 'w') { ++r, ++k; }
        for (int j = k; j < n * 2; ++j) {
            if (s[j] != 'w' && s[j] != s[k]) break;
            ++r;
        }
        ret = max(ret, l + r);
    }
    printf("%d\n", min(ret, n));

    return 0;
}

