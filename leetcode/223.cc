#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if (A > E) {
      return computeArea(E, F, G, H, A, B, C, D);
    }
    int a1 = (A - C) * (B - D);
    int a2 = (E - G) * (F - H);
    if (C <= E || H <= B || D <= F) {
      return a1 + a2;
    }
    int x = min(C, G) - E;
    int y = min(D, H) - max(B, F);
    return a1 + a2 - x * y;
  }
};

int main() {

  return 0;
}

