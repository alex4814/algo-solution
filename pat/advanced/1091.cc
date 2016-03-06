#include <cstdio>
#include <queue>

using namespace std;


const int M = 1300;
const int N = 130;
const int L = 65;

int m, n, l, t;
int g[L][M][N];
bool vis[L][M][N];
int volume;

struct Pixel {
  int i, j, k;
};

int di[] = { 0, 0, 0, 0, -1, 1 };
int dj[] = { 0, 1, -1, 0, 0, 0 };
int dk[] = { 1, 0, 0, -1, 0, 0 };

bool valid(int i, int j, int k) {
  return i >= 0 && i < l && j >= 0 && j < m && k >=0 && k < n;
}

int bfs(Pixel p) {
  static queue<Pixel> q;
  while (!q.empty()) {
    q.pop();
  }
  int count = 0;
  q.push(p);
  vis[p.i][p.j][p.k] = true;
  while (!q.empty()) {
    p = q.front(); q.pop();
    ++count;
    for (int i = 0; i < 6; ++i) {
      int ti = p.i + di[i];
      int tj = p.j + dj[i];
      int tk = p.k + dk[i];
      if (valid(ti, tj, tk) && g[ti][tj][tk] && !vis[ti][tj][tk]) {
        vis[ti][tj][tk] = true;
        Pixel tp = { ti, tj, tk };
        q.push(tp);
      }
    }
  }
  return count >= t ? count : 0;
}

int main() {
  scanf("%d %d %d %d", &m, &n, &l, &t);
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        scanf("%d", &g[i][j][k]);
      }
    }
  }
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        if (vis[i][j][k] || !g[i][j][k]) {
          continue;
        }
        Pixel p = { i, j, k };
        volume += bfs(p);
      }
    }
  }
  printf("%d\n", volume);
  return 0;
}
