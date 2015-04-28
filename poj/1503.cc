#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 105

char s[MAXN];
int d[MAXN];

int main() {
    while (scanf("%s", s)) {
        if (strcmp(s, "0") == 0) break;
        int n = strlen(s);
        for (int i = 0; i < n; ++i) {
            d[i] += s[n - 1 - i] - '0';
        }
    }
    for (int i = 0; i + 1 < MAXN; ++i) {
        if (d[i] >= 10) {
            d[i + 1] += d[i] / 10;
            d[i] %= 10;
        }
    }
    int k = MAXN;
    while (d[--k] == 0);
    while (k >= 0) printf("%d", d[k--]);
    printf("\n");

    return 0;
}
