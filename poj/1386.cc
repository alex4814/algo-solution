#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;
#define MAXN 1005

int T, n;
int in[26], out[26];
int g[26][26];
char word[MAXN];

int p[26];
int c[26];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void set_union(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    p[pu] = pv;
}

bool ok() {
    int f = -1;
    for (int i = 0; i < 26; ++i) {
        if (!c[i]) continue;
        if (f == -1) {
            f = find(i);
        } else {
            if (f != find(i)) return false;
        }
    }
    int nOut = 0, nIn = 0;
    for (int i = 0; i < 26; ++i) {
        if (in[i] - out[i] == 1) {
            ++nIn;
        } else if (out[i] - in[i] == 1) {
            ++nOut;
        } else if (in[i] == out[i]) {
            ;
        } else {
            return false;
        }
    }
    return nIn + nOut == 0 || nIn + nOut == 2;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(c, 0, sizeof(c));
        memset(p, -1, sizeof(p));
        memset(g, 0, sizeof(g));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", word);
            int u = word[0] - 'a';
            int v = word[ strlen(word) - 1 ] - 'a';
            c[u] = c[v] = 1;
            set_union(u, v);
            ++out[u], ++in[v];
        }

        puts(ok() ? "Ordering is possible." : "The door cannot be opened.");
    }
    return 0;
}
