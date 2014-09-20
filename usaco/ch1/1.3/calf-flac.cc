/*
ID: alex4814
PROG: calfflac
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

#define MAXN 20005
#define EPS 1e-8
#define INF 0x3f3f3f3f

char s[MAXN];
int n;

vector<pii> ps;

int main() {

#ifdef FILEIO
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
#endif

    int c;
    while ((c = getchar()) != EOF) {
        s[n++] = c;
    }
    for (int i = 0; i < n; ++i) {
        if (isalpha(s[i])) {
            ps.push_back(make_pair(tolower(s[i]), i));
        }
    }

    int length = 0;
    int b, e;

    int sz = ps.size();
    for (int i = 0; i < sz; ++i) {
        int k;
        for (k = 1; i - k >= 0 && i + k < sz; ++k) {
            if (ps[i - k].first != ps[i + k].first) break;
        }
        if (2 * k - 1 > length) {
            length = 2 * (k - 1) + 1;
            b = ps[i - (k - 1)].second;
            e = ps[i + (k - 1)].second;
        }
    }
    for (int i = 0; i + 1 < sz; ++i) {
        if (ps[i].first != ps[i + 1].first) continue;
        int k;
        for (k = 1; i - k >= 0 && i + 1 + k < sz; ++k) {
            if (ps[i - k].first != ps[i + 1 + k].first) break;
        }
        if (2 * k > length) {
            length = 2 * k;
            b = ps[i - (k - 1)].second;
            e = ps[i + 1 + (k - 1)].second;
        }
    }
    printf("%d\n", length);
    for (int i = b; i <= e; ++i) {
        putchar(s[i]);
    }
    printf("\n");

    return 0;
}
