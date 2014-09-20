/*
ID: alex4814
PROG: milk2
LANG: C++
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

#define MAXN 5005
#define EPS 1e-8

struct Interval {
    int b, e;
    bool operator < (const Interval &y) const {
        return b < y.b || (b == y.b && e < y.e);
    }
};

Interval milking[MAXN];
int n;

int main() {
#ifdef FILEIO
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &milking[i].b, &milking[i].e);
    }
    sort(milking, milking + n);

    int k = 1;
    for (int i = 1; i < n; ++i) {
        if (milking[i].b <= milking[k - 1].e) {
            milking[k - 1].e = max(milking[k - 1].e, milking[i].e);
        } else {
            milking[k++] = milking[i];
        }
    }

    int r1 = 0, r2 = 0;
    for (int i = 0; i < k; ++i) {
        r1 = max(r1, milking[i].e - milking[i].b);
        r2 = max(r2, i ? milking[i].b - milking[i - 1].e : 0);
    }
    printf("%d %d\n", r1, r2);

    return 0;
}

