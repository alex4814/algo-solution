#include <cstdio>
#include <cstring>

const int mod = 1000000007;
const int N = 100005;

char s[N];
int f[N][3];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'P') {
      f[i + 1][0] = f[i][0] + 1;
      f[i + 1][1] = f[i][1];
      f[i + 1][2] = f[i][2];
    } else if (s[i] == 'A') {
      f[i + 1][0] = f[i][0];
      f[i + 1][1] = (f[i][1] + f[i][0]) % mod;
      f[i + 1][2] = f[i][2];
    } else {
      f[i + 1][0] = f[i][0];
      f[i + 1][1] = f[i][1];
      f[i + 1][2] = (f[i][2] + f[i][1]) % mod;
    }
  }
  printf("%d\n", f[n][2]);
  return 0;
}
