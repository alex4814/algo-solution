#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int N = 100005;

int parent[N];
int u[N], v[N];
int uf_count;

void uf_init(int n) {
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }
  uf_count = n;
}

int uf_find(int p) {
  while (p != parent[p]) {
    p = parent[p];
  }
  return p;
}

bool uf_connected(int p, int q) {
  return uf_find(p) == uf_find(q);
}

void uf_union(int p, int q) {
  parent[q] = p;
  uf_count -= 1;
}

int main() {
  int x, y, n_case = 1;
  while (scanf("%d %d", &x, &y) == 2) {
    if (x == -1 && y == -1) break;

    int n = 0;
    vector<pii> e;
    while (x && y) {
      u[n] = x; v[n] = y;
      e.push_back(make_pair(x, n));
      e.push_back(make_pair(y, ~n));
      n += 1;
      scanf("%d %d", &x, &y);
    }
    sort(e.begin(), e.end());
    int t = 0;
    for (int i = 0; i < n + n; ++i) {
      if (e[i].second >= 0) {
        u[ e[i].second ] = t;
      } else {
        v[ ~e[i].second ] = t;
      }
      if (i + 1 < n + n && e[i].first != e[i + 1].first) {
        t += 1;
      }
    }

    bool tree = true;
    uf_init(t + 1);
    for (int i = 0; i < n; ++i) {
      if (parent[v[i]] != v[i] || u[i] == v[i]) {
        tree = false; break;
      }
      int ri = uf_find(u[i]);
      int rj = uf_find(v[i]);
      if (ri == rj) {
        tree = false; break;
      }
      uf_union(u[i], v[i]); 
    }
    if (uf_count != 1) {
      tree = false;
    }
    printf("Case %d is%sa tree.\n", n_case++, tree ? " " : " not ");
  }
  return 0;
}
