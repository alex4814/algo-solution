/*
 * Creation Date: 2016-05-22
 * Created By: alex4814
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const int N = 100005;
const int L = 40;

struct Node {
  int child[2];
};

unsigned long long a[N];
int n;

// trie[0] as root node
Node trie[N * L];
int cnt = 1;

void init(int x) {
  trie[x].child[0] = -1;
  trie[x].child[1] = -1;
}

void insert(unsigned long long num) {
  unsigned long long mask = 1ll << (L - 1);
  int p = 0; // root
  for (int i = 0; i < L; ++i) {
    int x = (num & mask) > 0;
    if (trie[p].child[x] == -1) {
      init(cnt);
      trie[p].child[x] = cnt++;
    }
    p = trie[p].child[x];
    mask >>= 1;
  }
}

unsigned long long query(unsigned long long num) {
  unsigned long long mask = 1ll << (L - 1);
  int p = 0; // root
  unsigned long long ret = 0;
  for (int i = 0; i < L; ++i) {
    int x = !((num & mask) > 0);
    if (trie[p].child[x] == -1) {
      x ^= 1;
    }
    p = trie[p].child[x];
    ret = (ret << 1) | x;
    mask >>= 1;
  }
  return ret;
}

int main() {
  // input array
  while (scanf("%d", &n) == 1) {

    for (int i = 0; i < n; ++i) {
      scanf("%llu", a + i);
    }

    // start with longest suffix
    unsigned long long suffix = 0;
    for (int i = 0; i < n; ++i) {
      suffix ^= a[i];
    }

    // initial setting
    unsigned long long ret = suffix; 
    init(0);
    insert(0);

    /* 
     * for each suffix calculate the maximal 
     * xor value for every non-intersect prefix
     */
    unsigned long long prefix = 0;
    for (int i = 0; i < n; ++i) {
      // remove i-th element from current suffix value
      suffix ^= a[i]; 
      // add i-th element to current prefix value
      prefix ^= a[i]; 

      // add current prefix xor value to trie
      insert(prefix); 
      unsigned long long q = query(suffix);

      // calculate the maximal xor value
      ret = max(ret, q ^ suffix);
    }

    printf("%llu\n", ret);
  }
  return 0;
}
