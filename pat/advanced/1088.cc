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

class Fraction {
  int numerator;
  int denominator;

  Fraction(int n, int d) {
    numerator = n;
    denominator = d;
  }

  int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }
}

Fraction Fraction::operator+(Fraction &a, Fraction &b) {
   
}

int main() {

  return 0;
}

