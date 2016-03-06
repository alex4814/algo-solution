#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1005;
int id[N], sz[N];
int h[N];

void uf_init(int n) {
  for (int i = 0; i < n; ++i) {
    id[i] = i;
  }
}

int uf_find(int p) {
  while (p != id[p]) {
    p = id[p];
  }  
  return p;
}

void uf_union(int p, int q) {
  int fp = uf_find(p);
  int fq = uf_find(q);
  if (fp == fq) return;
  id[fp] = fq;
  sz[fq] += sz[fp];
}

int main() {
  uf_init(N);
  int n;
  scanf("%d", &n);
  int M = 0;
  for (int i = 0, k; i < n; ++i) {
    scanf("%d:", &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", h + j);
      M = max(M, h[j]--);
    }
    if (k > 1) {
      for (int j = 1; j < k; ++j) {
        uf_union(h[0], h[j]);
      }
    }
    sz[uf_find(h[0])]++;
  }
  vector<int> cls;
  for (int i = 0; i < M; ++i) {
    cls.push_back(uf_find(i));
  }
  sort(cls.begin(), cls.end());
  auto it = unique(cls.begin(), cls.end());
  cls.resize(distance(cls.begin(), it));

  vector<int> ret;
  for (int i = 0; i < cls.size(); ++i) {
    if (sz[cls[i]] > 0) {
      ret.push_back(sz[cls[i]]);
    }
    //printf("%d\n", cls[i]);
  }
  sort(ret.begin(), ret.end());
  int mm = ret.size();
  printf("%d\n", mm);
  for (int i = mm - 1; i >= 0; --i) {
    printf("%d%c", ret[i], i ? ' ' : '\n');
  }
  return 0;
}
