#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 50005;

int id[3 * MAXN];
int sz[3 * MAXN];

void uf_init(int n) {
  for (int i = 0; i < n; ++i) {
    id[i] = i;
    sz[i] = 1;
  }
}

int uf_find(int p) {
  int rt = p;
  while (rt != id[rt]) {
    rt = id[rt];
  }
  while (p != rt) {
    int tp = id[p];
    id[p] = rt;
    p = tp;
  }
  return rt;
}

bool uf_connected(int p, int q) {
  return uf_find(p) == uf_find(q);
}

void uf_union(int p, int q) {
  int i = uf_find(p);
  int j = uf_find(q);
  if (i == j) return;

  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  uf_init(3 * n);
  int ret = 0;
  while (k--) {
    int d, x, y;
    scanf("%d %d %d", &d, &x, &y);
    if (x > n || y > n) {
      ret += 1; continue;
    }
    x -= 1; y -= 1; 
    if (d == 1) {
      if (uf_connected(x, y + n) || uf_connected(x, y + n + n)) {
        ret += 1; continue;
      } else {
        uf_union(x, y);
        uf_union(x + n, y + n);
        uf_union(x + n + n, y + n + n);
      }
    } else {
      if (uf_connected(x, y) || uf_connected(x, y + n + n)) {
        ret += 1; continue;
      } else {
        uf_union(x, y + n);
        uf_union(x + n, y + n + n);
        uf_union(x + n + n, y);
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}
