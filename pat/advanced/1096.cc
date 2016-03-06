#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int x = sqrt(n);
  int len = 0;
  vector<int> f;
  for (int p = 2; p <= x; ++p) {
    int m = n, q = p;
    int rlen = 0;
    vector<int> rf;
    while (m % q == 0) {
      rf.push_back(q);
      m /= q++;
      rlen += 1;
    }
    if (rlen > len) {
      len = rlen;
      f = rf;
    }
  }
  if (len == 0) {
    len = 1;
    f.push_back(n);
  }
  printf("%d\n", len);
  for (int i = 0; i < f.size(); ++i) {
    if (i) putchar('*');
    printf("%d", f[i]);
  }
  putchar('\n');
  return 0;
}
