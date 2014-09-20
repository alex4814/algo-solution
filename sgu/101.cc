#include <cstdio>
#include <cstring>
using namespace std;

#define MAXV 7
#define MAXE 200

int first[MAXV], next[MAXE];
int u[MAXE], v[MAXE];

int deg[MAXV];
int n;
int start;

int stack[MAXE + 1], _n;
int path[MAXE], _m;
int ret[MAXE], _r;
bool mark[MAXE];

void add(int s, int t) {
    static int e = 0;
    u[e] = s, v[e] = t;
    next[e] = first[s];
    first[s] = e++;
}

void dfs(int x) {
    stack[++_n] = x;
    for (int e = first[x]; e != -1; e = next[e]) {
        if (!mark[e]) {
            mark[e] = mark[e ^ 1] = true;
            path[++_m] = e;
            dfs(v[e]);
            //printf("%d\n", v[e]);
            break;
        }
    }
}
void fleury(int s) {
    bool extendable;

    _n = _m = -1;
    stack[++_n] = s;
    while (_n >= 0) {
        extendable = false;
        for (int e = first[ stack[_n] ]; e != -1; e = next[e]) {
            if (!mark[e]) {
                extendable = true;
                break;
            }
        }
        if (extendable) {
            dfs(stack[_n--]);
        } else {
            if (_n) { ret[_r++] = path[_m]; };
            _n--, _m--;
        }
    }
}

int main() {
    memset(first, -1, sizeof(first));

    scanf("%d", &n);
    for (int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        add(a, b); add(b, a);
        deg[a]++; deg[b]++;
        start = a;
    }

    int oddDegCnt = 0;
    for (int i = 0; i < MAXV; ++i) {
        if (deg[i] & 1) {
            oddDegCnt++;
            start = i;
        }
    }
    if (oddDegCnt == 0 || oddDegCnt == 2) {
        _r = 0;
        fleury(start);
        if (_r != n) {
            printf("No solution\n");
        } else {
            for (int i = 0; i < _r; ++i) {
                printf("%d %c\n", ret[i] / 2 + 1, (ret[i] & 1) ? '+' : '-');
            }
        }
    } else {
        printf("No solution\n");
    }

    return 0;
}
