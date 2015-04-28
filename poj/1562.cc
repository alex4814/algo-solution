#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 105

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 8; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (!vis[tx][ty] && g[tx][ty] == '@') {
            dfs(tx, ty);
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0) break;
        memset(g, 0, sizeof(g));
        memset(vis, false, sizeof(vis));

        for (int i = 1; i <= n; ++i) {
            scanf("%s", g[i] + 1);
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!vis[i][j] && g[i][j] == '@') {
                    dfs(i, j); ++ret;
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}


