#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 105

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
            for (int k = 0; k < n; ++k) {
                r = max(r, eliminate(t));
            }
        }
    }
    return 0;
}
