#include <cstdio>
#include <map>

using namespace std;

map<int, int> m;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0, x, y; i < n; ++i) {
    scanf("%d %d", &x, &y);
    m[x] += y;
  }
  map<int, int>::iterator it;
  int x, y = 0;
  for (it = m.begin(); it != m.end(); ++it) {
    if (it->second > y) {
      x = it->first;
      y = it->second;
    }
  }
  printf("%d %d\n", x, y);
  return 0;
}
