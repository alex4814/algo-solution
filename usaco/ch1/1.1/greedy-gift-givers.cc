/*
ID: alex4814
PROG: gift1
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
#define MAXLEN 20
#define EPS 1e-8

int n;
char name[MAXN][MAXLEN];
int net[MAXN];

int id_of(char *s) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(s, name[i]) == 0) return i;
    }
    return -1;
}

int main() {
#ifdef FILEIO
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", name[i]);
    }

    char s[MAXLEN];
    int amt, m, u, v;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d", s, &amt, &m);
        u = id_of(s);

        for (int k = 0; k < m; ++k) {
            scanf("%s", s);
            v = id_of(s);
            net[u] -= amt / m;
            net[v] += amt / m;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%s %d\n", name[i], net[i]);
    }
    return 0;
}

