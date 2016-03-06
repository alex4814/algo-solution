#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int a[10005];
int mat[MAXN][MAXN];
bool vis[MAXN][MAXN];

// a >= b
void cal(int n, int &a, int &b) {
  int p = -1, q, mlen = n, x = sqrt(n);
  for (int i = 1; i <= x; ++i) {
    if (n % i) continue;
    if (n / i - i < mlen) {
      mlen = n / i - i;
      p = n / i, q = i;
    }
  }
  a = p, b = q;
}

// right, down, left, up
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

void next_point(int &x, int &y, int &d, int m, int n) {
  int tx = x + dr[d];
  int ty = y + dc[d];
  if (tx >= 0 && tx < m && ty >= 0 && ty < n && !vis[tx][ty]) {
    x = tx, y = ty;
    return;
  }
  d = (d + 1) % 4;
  x = x + dr[d];
  y = y + dc[d];
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  sort(a, a + n);

  int r, c;
  cal(n, r, c);
  
  // fill
  int ip = 0, jp = 0, d = 0;
  for (int i = n - 1; i >= 0; --i) {
    mat[ip][jp] = a[i];
    vis[ip][jp] = true;
    next_point(ip, jp, d, r, c);
  }

  // print
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      printf("%d%c", mat[i][j], j + 1 == c ? '\n' : ' ');
    }
  }
  return 0;
}
