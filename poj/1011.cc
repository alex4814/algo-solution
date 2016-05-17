#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 205;

struct Jury {
  int p, d;
  int ix;
  bool operator < (const Jury &b) const {
    return ix < b.ix;
  }
};

int tot;
Jury jury[N];

bool cmp(Jury a, Jury b) {
  int da = abs(tot + (a.p - a.d));
  int db = abs(tot + (b.p - b.d));
  if (da == db) {
    return a.p + a.d > b.p + b.d;
  }
  return da < db;
}

int main() {
  int n, m, n_case = 1;
  while (scanf("%d %d", &n, &m), n && m) {
    tot = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &jury[i].p, &jury[i].d);
      jury[i].ix = i + 1;
    }

    vector<int> ret;
    for (int i = 0; i < m; ++i) {
      sort(jury + i, jury + n, cmp);
      ret.push_back(jury[i].ix);
      tot += jury[i].p - jury[i].d;
    }

    sort(jury, jury + n);
    int bp = 0, bd = 0;
    for (int i = 0; i < m; ++i) {
      bp += jury[ret[i] - 1].p;
      bd += jury[ret[i] - 1].d;
    }
    printf("Jury #%d\n", n_case++);
    printf("Best jury has value %d for prosecution and value %d for defence:\n", bp, bd);
    for (int i = 0; i < m; ++i) {
      printf(" %d", ret[i]);
    }
    putchar('\n');
  }
  return 0;
}
