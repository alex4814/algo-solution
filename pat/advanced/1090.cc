#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int N = 100005;

vector<int> g[N];
int cnt, maxf = 0;

void dfs(int nd, int lvl) {
  int n = g[nd].size();
  if (n == 0) {
    if (lvl > maxf) {
      cnt = 1;
      maxf = lvl;
    } else if (lvl == maxf) {
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
  int root = -1;
  for (int i = 0, k; i < n; ++i) {
    scanf("%d", &k);
    if (k == -1) {
      root = i; continue;
    }
    g[k].push_back(i);
  }
  dfs(root, 0);
  double rate = pow(1 + r / 100, maxf);
  printf("%.2f %d\n", p * rate, cnt);
  return 0;
}
