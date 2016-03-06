#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  double r = 0, x;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &x);
    r += x * (i + 1) * (n - i);
  }
  printf("%.2f\n", r);
  return 0;
}
