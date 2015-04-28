#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

#define MAXN 15

typedef long long ll;
char n[2][MAXN];
int tag, cmp;

inline int sgn(ll x) {
    return (x > 0) - (x < 0);
}

ll convert(char *s, ll r) {
    ll ret = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        ret = ret * r + (isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10);
    }
    return ret;
}

int min_radix(char *s) {
    int ret = 1;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        ret = max(ret, isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10);
    }
    return ret + 1;
}

int compare(ll x, char *a, ll r) {
    ll s = 0;
    int len = strlen(a);
    for (int i = 0; i < len; ++i) {
        s = s * r + (isdigit(a[i]) ? a[i] - '0' : a[i] - 'a' + 10);
        if (x < s || s < 0) return -1;
    }
    return sgn(x - s);
}

ll possible(ll x) {
    ll l = min_radix(n[tag ^ 1]), r = (x > l) ? x : l;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if ((cmp = compare(x, n[tag ^ 1], m)) == 0) return m;
        cmp < 0 ? r = m - 1 : l = m + 1;
    }
    return -1;
}

int main() {
    ll radix;
    scanf("%s%s%d%lld", n[0], n[1], &tag, &radix); --tag;
    ll x = convert(n[tag], radix), ret;

    (ret = possible(x)) != -1 ? printf("%lld\n", ret) : printf("Impossible\n");
    return 0;
}
