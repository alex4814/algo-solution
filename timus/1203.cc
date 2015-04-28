#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100000
#define MAXT 30000

struct Report {
    int s, e;
    bool operator < (const Report &b) const {
        return s < b.s || (s == b.s && e < b.e);
    }
};


int c[MAXT + 1];
Report r[MAXN];
int n;

int max_cnt_before(int ix) {
    static int preMaxCnt = 0;
    static int preMaxCntIndex = 0;
    for (int i = preMaxCntIndex + 1; i <= ix; ++i) {
        preMaxCnt = max(preMaxCnt, c[i]);
    }
    preMaxCntIndex = ix;
    return preMaxCnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &r[i].s, &r[i].e);
    }
    sort(r, r + n);

    int _n = 1;
    for (int i = 1; i < n; ++i) {
        if (r[i].s != r[i - 1].s) {
            r[_n++] = r[i];
        }
    }
    n = _n;

    for (int i = 0; i < n; ++i) {
        c[ r[i].e ] = max(c[ r[i].e ], max_cnt_before(r[i].s - 1) + 1);
    }

    int ret = 0;
    for (int i = 0; i <= MAXT; ++i) {
        ret = max(ret, c[i]);
    }
    printf("%d\n", ret);
    return 0;
}
