#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int N = 100005;

vector<int> g[N];
int cnt, minf = N;

void dfs(int nd, int lvl) {
  int n = g[nd].size();
  if (n == 0) {
    if (lvl < minf) {
      cnt = 1;
      minf = lvl;
    } else if (lvl == minf) {
      ++cnt;
    }
    return;
  }
  for (int i = 0; i < n; ++i) {
    dfs(g[nd][i], lvl + 1);
  }
}

int main() {
  int n;
  double p, r;
  scanf("%d %lf %lf", &n, &p, &r);
  for (int i = 0, k; i < n; ++i) {
    scanf("%d", &k);
    for (int j = 0, x; j < k; ++j) {
      scanf("%d", &x);
      g[i].push_back(x);
    }
  }
  dfs(0, 0);
  double rate = pow(1 + r / 100, minf);
  printf("%.4f %d\n", p * rate, cnt);
  return 0;
}
