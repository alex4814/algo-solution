#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100005;

int a[N];
int lmax[N], rmin[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  lmax[0] = a[0];
  for (int i = 1; i < n; ++i) {
    lmax[i] = max(lmax[i - 1], a[i]);
  }
  rmin[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    rmin[i] = min(a[i], rmin[i + 1]);
  }
  vector<int> r;
  for (int i = 0; i < n; ++i) {
    if (lmax[i] == a[i] && rmin[i] == a[i]) {
      r.push_back(a[i]);
    }
  }
  sort(r.begin(), r.end());
  int m = r.size();
  printf("%d\n", m);
  for (int i = 0; i < m; ++i) {
    printf("%d%c", r[i], i + 1 == m ? '\n' : ' ');
  }
  if (m == 0) {
    printf("\n");
  }
  return 0;
}
