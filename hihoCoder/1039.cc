#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 105

// add letter i at position k in s to construct t
void convert(char *s, char *t, int letter, int pos, int n) {
    strncpy(t, s, pos);
    t[pos] = letter + 'A';
    strncpy(t + pos + 1, s + pos, n - pos);
    t[n + 1] = '\0';
}

int eliminate(char *s) {
    static short f[MAXN];
    memset(f, 0, sizeof(f));
    int n = strlen(s);
    bool primitive = false;
    while (!primitive) {
        primitive = true;
        int b = -1;
        for (int i = 0; i < n; ++i) {
            if (f[i]) continue;
            b = i; break;
        }
        for (int i = b + 1; i < n; ++i) {
            if (f[i]) continue;
            if (s[i] == s[b]) {
                f[i] = f[b] = 1;
                primitive = false;
            }
            b = i;
        }
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        r += f[i];
    }
    return r;
}

char s[MAXN];
char t[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int n = strlen(s);
        int r = 0;
        for (int i = 0; i < 3; ++i) {
            for (int k = 0; k <= n; ++k) {
                convert(s, t, i, k, n);
                r = max(r, eliminate(t));
            }
        }
        printf("%d\n", r);
    }
    return 0;
}
