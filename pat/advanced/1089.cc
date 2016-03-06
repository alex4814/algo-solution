#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;

int a[N], b[N], c[N];
int n;

bool equal() {
  for (int i = 0; i < n; ++i) {
    if (b[i] != c[i]) {
      return false;
    }
  }
  return true;
}

void print() {
  for (int i = 0; i < n; ++i) {
    printf("%d%c", c[i], i + 1 == n ? '\n' : ' ');
  }
}

bool insertion() {
  for (int i = 0; i < n; ++i) {
    c[i] = a[i];
  }
  bool iter = false;
  for (int i = 1; i < n; ++i) {
    if (iter && !equal()) {
      return true;
    }
    for (int j = i; j > 0; --j) {
      if (c[j] < c[j - 1]) {
        swap(c[j], c[j - 1]);
      }
    }
    if (equal()) {
      iter = true;
    }
  }
  return false;
}

bool merge() {
  for (int i = 0; i < n; ++i) {
    c[i] = a[i];
  }
  bool iter = false;
  for (int s = 2; s <= n * 2; s <<= 1) {
    if (iter && !equal()) {
      return true;
    }
    for (int i = 0; i < n; i += s) {
      if (i + s > n) {
        sort(c + i, c + n);
      } else {
        sort(c + i, c + i + s);
      }
    }
    if (equal()) {
      iter = true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  if (insertion()) {
    printf("Insertion Sort\n");
    print();
  } else if (merge()) {
    printf("Merge Sort\n");
    print();
  }
  return 0;
}
