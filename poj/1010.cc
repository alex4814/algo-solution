#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 55;

struct Seq {
  vector<int> s;
  int n;

  bool operator < (const Seq &b) const {
    if (n == b.n && s.size() == b.s.size()) {
      return *(s.rbegin()) > *(b.s.rbegin());
    } else if (n == b.n) {
      return s.size() < b.s.size();
    } else {
      return n > b.n;
    }
  }
};

bool operator == (const Seq &a, const Seq &b) {
  return a.n == b.n && a.s.size() == b.s.size() && *(a.s.rbegin()) == *(b.s.rbegin());
}

void print(vector<int> &s) {
  int sz = s.size();
  for (int i = 0; i < sz; ++i) {
    printf("%d%c", s[i], i + 1 == sz ? '\n' : ' ');
  }
}

int d[N], n;
Seq s;
vector<Seq> ret;

void dfs(int ix, int left, int target) {
  if (target < 0) return;

  if (target == 0) {
    ret.push_back(s);
    return;
  }

  for (int i = ix; i < n; ++i) {
    if (left * d[n - 1] < target || d[i] > target) {
      break;
    }
    if ((left - 1) * d[n - 1] < target - d[i]) {
      continue;
    }
    if (i != ix) {
      ++s.n;
    }
    s.s.push_back(d[i]);
    dfs(i, left - 1, target - d[i]);
    s.s.pop_back();
    if (i != ix) {
      --s.n;
    }
  }
}

int main() {
  while (scanf("%d", &d[n++]) != EOF) {
    int x;
    while (scanf("%d", &x), x) {
      d[n++] = x;
    }
    sort(d, d + n);

    int t = 1, cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (d[i] == d[i - 1]) {
        ++cnt;
        if (cnt <= 4) {
          d[t++] = d[i];
        }
      } else {
        d[t++] = d[i];
        cnt = 1;
      }
    }
    n = t;

    while (scanf("%d", &x), x) {
      ret.clear();
      int left = 4, target = x;
      for (int i = 0; i < n; ++i) {
        if (left * d[n - 1] < target || d[i] > target) {
          break;
        }
        if ((left - 1) * d[n - 1] < target - d[i]) {
          continue;
        }
        s.s.push_back(d[i]);
        s.n = 1;
        dfs(i, 3, x - d[i]);
        s.n = 0;
        s.s.pop_back();
      }
      sort(ret.begin(), ret.end());
      if (ret.size() > 1 && ret[0] == ret[1]) {
        printf("%d (%d): tie\n", x, ret[0].n);
      } else if (ret.size() == 0) {
        printf("%d ---- none\n", x);
      } else {
        printf("%d (%d): ", x, ret[0].n);
        print(ret[0].s);
      }
    }

    n = 0;
  }
  return 0;
}
