/*
ID: alex4814
PROG: ride
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

#define MAXN 10
#define EPS 1e-8
#define MOD 47

char n[2][MAXN];

int number_of(char *s) {
    int ret = 1;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        ret = ret * (s[i] - 'A' + 1) % MOD;
    }
    return ret;
}

int main() {
#ifdef FILEIO
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
#endif

    scanf("%s %s", n[0], n[1]);
    puts(number_of(n[0]) == number_of(n[1]) ? "GO" : "STAY");
    return 0;
}

