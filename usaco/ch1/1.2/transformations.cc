/*
ID: alex4814
PROG: transform
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

#define MAXN 15
#define EPS 1e-8

int n;

struct Pattern {
    char g[MAXN][MAXN];
    bool operator == (const Pattern &b) const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] != b.g[i][j]) return false;
            }
        }
        return true;
    }
};

Pattern s, t;

Pattern rotate(Pattern p) {
    Pattern d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d.g[j][n - 1 - i] = p.g[i][j];
        }
    }
    return d;
}

Pattern reflect(Pattern p) {
    Pattern d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d.g[i][n - 1 - j] = p.g[i][j];
        }
    }
    return d;
}

int main() {
#ifdef FILEIO
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s.g[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", t.g[i]);
    }

    int ret = 0;
    if (rotate(s) == t) {
        ret = 1;
    } else if (rotate(rotate(s)) == t) {
        ret = 2;
    } else if (rotate(rotate(rotate(s))) == t) {
        ret = 3;
    } else {
        s = reflect(s);
        if (s == t) {
            ret = 4;
        } else if (rotate(s) == t) {
            ret = 5;
        } else if (rotate(rotate(s)) == t) {
            ret = 5;
        } else if (rotate(rotate(rotate(s))) == t) {
            ret = 5;
        } else if (reflect(s) == t) {
            ret = 6;
        } else {
            ret = 7;
        }
    }
    printf("%d\n", ret);

    return 0;
}

