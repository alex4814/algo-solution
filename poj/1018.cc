#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;

struct Device {
  int b, p;
};

bool operator < (const Device &a, const Device &b) {
  return a.b < b.b;
}

Device dev[N][N];
int st[N], cnt[N];
int minp[N][N];
int bws[N * N], k;

// O(n^3 * log(n))
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    k = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", cnt + i);
      st[i] = 0;
      for (int j = 0; j < cnt[i]; ++j) {
        scanf("%d %d", &dev[i][j].b, &dev[i][j].p);
        bws[k++] = dev[i][j].b;
      }
      // minp[i][j], for ith device the minimun price among [j..end) manufactures;
      sort(dev[i], dev[i] + cnt[i]);
      minp[i][cnt[i] - 1] = dev[i][cnt[i] - 1].p;
      for (int j = cnt[i] - 2; j >= 0; --j) {
        minp[i][j] = min(dev[i][j].p, minp[i][j + 1]);
      }
    }
    /*
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        printf("%d%c", minp[i][j], j + 1 == cnt[i] ? '\n' : ' ');
      }
    }*/
    sort(bws, bws + k);
    double ret = 0;
    for (int i = 0; i < k; ++i) {
      if (i && bws[i] == bws[i - 1]) {
        continue;
      }
      double p = 0;
      for (int j = 0; j < n; ++j) {
        int lo = st[j], hi = cnt[j];
        while (lo < hi) {
          int mid = lo + (hi - lo) / 2;
          if (dev[j][mid].b >= bws[i]) {
            hi = mid;
          } else {
            lo = mid + 1;
          }
        }
        if (lo >= cnt[j]) goto result;
        st[j] = lo;
        p += minp[j][lo];
      }
      ret = max(ret, bws[i] / p);
    }
result:
    printf("%.3f\n", ret);
  }
  return 0;
}
