#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100005;

void left_shift(int len) {
  unsigned x = ~0u << (32 - len);
  printf("%08x\n", x);
}

void left_shift() {
  unsigned x = ~0u << (32 - 0);
  printf("%08x\n", x);
}

int main() {
  left_shift();   // prints "00000000"
  left_shift(0);  // prints "ffffffff"
  return 0;
}
