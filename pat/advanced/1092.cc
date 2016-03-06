#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;

char a[N], b[N];
int beads[256];

int main() {
  scanf("%s %s", a, b);
  bool buy = true;
  int alen = strlen(a);
  for (int i = 0; i < alen; ++i) {
    beads[a[i]] += 1;
  }
  int cnt = 0;
  int blen = strlen(b);
  for (int i = 0; i < blen; ++i) {
    if (beads[b[i]] == 0) {
      ++cnt;
    } else {
      beads[b[i]] -= 1;
    }
  }
  if (cnt == 0) {
    printf("Yes %d\n", alen - blen);
  } else {
    printf("No %d\n", cnt);
  }
  return 0;
}
