#include <cstdio>
#include <cstring>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int N = 105;
int l[N], r[N], v[N], ch[N][2];
int a[N];

int count_children(int rt) {
  if (rt == -1) {
    return 0;
  }
  if (ch[rt][0] + ch[rt][1] != -2) {
    return ch[rt][0] + ch[rt][1];
  }
  ch[rt][0] = l[rt] != -1 ? count_children(l[rt]) + 1 : 0; 
  ch[rt][1] = r[rt] != -1 ? count_children(r[rt]) + 1 : 0;
  return ch[rt][0] + ch[rt][1];
}

// [p, q)
void set_value(int rt, int p, int q) {
  if (rt == -1) {
    return;
  }
  v[rt] = a[p + ch[rt][0]];
  set_value(l[rt], p, p + ch[rt][0]);
  set_value(r[rt], p + ch[rt][0] + 1, q);
}

void level_print(int rt) {
  deque<int> q;
  vector<int> ret;
  q.push_back(rt);
  while (!q.empty()) {
    int x = q.front();
    ret.push_back(v[x]);
    q.pop_front();
    if (l[x] != -1) {
      q.push_back(l[x]);
    }
    if (r[x] != -1) {
      q.push_back(r[x]);
    }
  }
  int n = ret.size();
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ret[i], i + 1 == n ? '\n' : ' ');
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", l + i, r + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  memset(ch, -1, sizeof(ch));
  count_children(0);
  sort(a, a + n);
  set_value(0, 0, n);
  level_print(0);
  return 0;
}
