#include <cstdio>
#include <string>
#include <deque>
#include <vector>

using namespace std;

const int N = 10;
int ch[N][2];
bool hp[N];

void level_order(int rt) {
  deque<int> q;
  q.push_back(rt);
  bool start = false;
  while (!q.empty()) {
    if (start) putchar(' ');
    else start = true;
    int x = q.front();
    printf("%d", x);
    q.pop_front();
    if (ch[x][0] != -1) {
      q.push_back(ch[x][0]);
    }
    if (ch[x][1] != -1) {
      q.push_back(ch[x][1]);
    }
  }
  putchar('\n');
}

vector<int> inn;
void in_order(int rt) {
  if (rt == -1) {
    return;
  }
  in_order(ch[rt][0]);
  inn.push_back(rt);
  in_order(ch[rt][1]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char a[3], b[3];
    scanf("%s %s", a, b);
    if (a[0] == '-') {
      ch[i][1] = -1;
    } else {
      ch[i][1] = stoi(a);
      hp[ch[i][1]] = true;
    }
    if (b[0] == '-') {
      ch[i][0] = -1;
    } else {
      ch[i][0] = stoi(b);
      hp[ch[i][0]] = true;
    }
  }
  int rt = -1;
  for (int i = 0; i < n; ++i) {
    if (hp[i] == false) {
      rt = i; break;
    }
  }
  /*
  printf("root is: %d\n", rt);
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", ch[i][0], ch[i][1]);
  }
  */
  level_order(rt);
  in_order(rt);
  int m = inn.size();
  for (int i = 0; i < m; ++i) {
    printf("%d%c", inn[i], i + 1 == m ? '\n' : ' ');
  }
  return 0;
}
