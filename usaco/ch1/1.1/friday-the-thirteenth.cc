/*
ID: alex4814
PROG: friday
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

#define MAXN 100005
#define EPS 1e-8

struct Date {
    int y, m, d;
};

inline bool is_leap(int year) {
    return year % 400 == 0 || (year % 100 && year % 4 == 0);
}

int mth[2][13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

// 0 for Saturday
int cnt[7];
int n;

void count_13th_between(Date t) {
    static int day = 2;
    for (int y = 1900; y < t.y; ++y) {
        int c = is_leap(y);
        for (int m = 1; m <= 12; ++m) {
            for (int d = 1; d <= mth[c][m]; ++d) {
                if (d == 13) {
                    cnt[day]++;
                }
                day = (day + 1) % 7;
            }
        }
    }
}

int main() {
#ifdef FILEIO
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
#endif

    scanf("%d", &n);
    count_13th_between((Date){1900 + n, 1, 1});
    for (int i = 0; i < 7; ++i) {
        printf("%d%c", cnt[i], i + 1 == 7 ? '\n' : ' ');
    }
    return 0;
}

