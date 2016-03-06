#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;

void copy(int *a, int *b, int n) {
  for (int i = 0; i < n; ++i) {
    b[i] = a[i];
  }
}

void print(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
  }
}

bool equal(int *a, int *b, int n) {
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int c[N];

bool insertion_sort(int *a, int *b, int n) {
  copy(a, c, n);
  int iter = 0;
  for (int i = 1; i < n; ++i) {
    if (iter && !equal(c, b, n)) {
      return true;
    }
    for (int j = i; j > 0; --j) {
      if (c[j] < c[j - 1]) {
        swap(c[j], c[j - 1]);
      }
    }
    if (equal(c, b, n)) {
      iter = 1;
    }
  }
  return false;
}

void heapify(int *a, int p, int n) {
  while (2 * p + 1 < n) {
    int l = 2 * p + 1;
    if (l + 1 < n) {
      if (a[l] < a[l + 1]) {
        l = l + 1;
      }
    }
    if (a[l] > a[p]) {
      swap(a[l], a[p]);
    }
    p = l;
  }
}

void build_heap(int *a, int n) {
  for (int i = n / 2; i >= 0; --i) {
    heapify(a, i, n);
  }
}

bool heap_sort(int *a, int *b, int n) {
  copy(a, c, n);
  int iter = 0, m = n;
  build_heap(c, n);
  if (equal(c, b, m)) {
    iter = 1;
  }
  while (n > 1) {
    if (iter && !equal(c, b, m)) {
      return true;
    }
    swap(c[0], c[--n]);
    heapify(c, 0, n);
    //make_heap(c, c + n);
    //pop_heap(c, c + n);
    n -= 1;
    if (equal(c, b, m)) {
      iter = 1;
    }
  }
  return false;
}

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  if (insertion_sort(a, b, n)) {
    printf("Insertion Sort\n");
    print(c, n);
  }
  if (heap_sort(a, b, n)) {
    printf("Heap Sort\n");
    print(c, n);
  }
  return 0;
}
