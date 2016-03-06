#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int p;
vector<int> r;
int sumr;
vector<int> kp;

constexpr int N = 21;
int intp[N];

inline int npow(int b, int e) {
  int ret = 1;
  for (int i = 0; i < e; ++i) {
    ret *= b;
  }
  return ret;
}

void dfs(int n, int k, int pre) {
  if (n == 0 && k == 0) {
    int s = 0, m = kp.size();
    for (int i = 0; i < m; ++i) {
      s += kp[i];
    }
    if (s > sumr) {
      sumr = s;
      r = kp;
    } else if (s == sumr) {
      bool chg = false;
      for (int i = 0; i < m; ++i) {
        if (kp[i] > r[i]) {
          chg = true; break;
        } else if (kp[i] < r[i]) {
          break;
        }
      }
      if (chg) {
        r = kp;
      }
    }
    return;
  }
  if (n < k) return;
  if (n != 0 && k == 0) {
    return;
  }
  int x = pow(n, 1.0 / p);
  x = min(x, pre);
  int y = ceil(pow(n * 1.0 / k, 1.0 / p));
  //printf("n=%d k=%d x=%d y=%d\n", n, k, x, y);
  for (int i = x; i >= y; --i) {
    kp.push_back(i);
    dfs(n - intp[i], k - 1, i);
    kp.pop_back();
  }
}

int main() {
  int n, k;
  scanf("%d %d %d", &n, &k, &p);
  int x = pow(n, 1.0 / p);
  for (int i = 1; i <= x; ++i) {
    intp[i] = npow(i, p);
  }
  dfs(n, k, n);
  if (r.empty()) {
    printf("Impossible\n");
  } else {
    printf("%d = ", n);
    int m = r.size();
    for (int i = 0; i < m; ++i) {
      printf("%d^%d%s", r[i], p, i + 1 == m ? "\n" : " + ");
    }
  }
  return 0;
}
