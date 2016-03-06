#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100005;
const int M = 10005;

int mem[N], nxt[N];
bool num[M];

int main() {
  int s, n;
  scanf("%d %d", &s, &n);
  int addr, key, next;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &addr, &key, &next);
    mem[addr] = key;
    nxt[addr] = next;
  }
  int rs = -1;
  int head = s, beforehead = s, rhead = -1;
  while (head != -1) {
    int x = abs(mem[head]);
    if (num[x]) {
      nxt[beforehead] = nxt[head];
      if (rs == -1) {
        rs = rhead = head;
      } else {
        nxt[rhead] = head;
        rhead = head;
      }
      nxt[rhead] = -1;
      head = nxt[beforehead];
    } else {
      num[x] = true;
      beforehead = head;
      head = nxt[head];
    }
  }
  while (s != -1) {
    printf("%05d %d ", s, mem[s]);
    if (nxt[s] != -1) {
      printf("%05d\n", nxt[s]);
    } else {
      printf("%d\n", nxt[s]);
    }
    s = nxt[s];
  }
  while (rs != -1) {
    printf("%05d %d ", rs, mem[rs]);
    if (nxt[rs] != -1) {
      printf("%05d\n", nxt[rs]);
    } else {
      printf("%d\n", nxt[rs]);
    }
    rs = nxt[rs];
  }
  return 0;
}
