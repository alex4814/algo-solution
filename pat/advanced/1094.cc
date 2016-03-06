#include <cstdio>
#include <vector>

using namespace std;

const int N = 105;
vector<int> g[N];
int lvl[N];

void dfs(int id, int lv) {
  lvl[lv] += 1;
  for (int i = 0; i < g[id].size(); ++i) {
    dfs(g[id][i], lv + 1);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int k, x, y;
    scanf("%d %d", &x, &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &y);
      g[x].push_back(y);
    }
  }
  dfs(1, 1);
  int cnt = 0, lv = 0;
  for (int i = 1; i < N; ++i) {
    if (lvl[i] > cnt) {
      cnt = lvl[i];
      lv = i;
    }
  }
  printf("%d %d\n", cnt, lv);
  return 0;
}
