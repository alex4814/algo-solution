#include <cstdio>
#include <cctype>

char id[19];
int w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[] = "10X98765432";
const int mod = 11;

int main() {
  int n;
  scanf("%d", &n);
  bool allpass = true;
  for (int i = 0; i < n; ++i) {
    scanf("%s", id);
    bool pass = true;
    int z = 0;
    for (int k = 0; k < 17; ++k) {
      if (!isdigit(id[k])) {
        pass = false;
        break;
      }
      z += w[k] * (id[k] - '0');
    }
    z %= 11;
    if (id[17] != m[z]) {
      pass = false;
    }
    if (!pass) {
      allpass = false;
      printf("%s\n", id);
    }
  }
  if (allpass) {
    printf("All passed\n");
  }
  return 0;
}
