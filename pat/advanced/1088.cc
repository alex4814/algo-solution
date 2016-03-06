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

long gcd(long a, long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
  
struct Fraction {
  void simplify() {
    long x = gcd(labs(numerator), denominator);
    numerator /= x;
    denominator /= x;
  }

  long numerator;
  long denominator;

  bool isInf() const {
    return denominator == 0;
  }

  Fraction(long n, long d) {
    long x = gcd(labs(n), d);
    numerator = n / x;
    denominator = d / x;
  }

  Fraction& operator+=(const Fraction &rhs) {
    numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    denominator *= rhs.denominator;
    simplify();
    return *this;
  }
  Fraction& operator-=(const Fraction &rhs) {
    numerator = numerator * rhs.denominator - denominator * rhs.numerator;
    denominator *= rhs.denominator;
    simplify();
    return *this;
  }
  Fraction& operator*=(const Fraction &rhs) {
    denominator *= rhs.denominator;
    numerator *= rhs.numerator;
    simplify();
    return *this;
  }
  Fraction& operator/=(const Fraction &rhs) {
    denominator *= rhs.numerator;
    numerator *= rhs.denominator;
    simplify();
    if (denominator < 0) {
      denominator *= -1;
      numerator *= -1;
    }
    return *this;
  }
};

ostream& operator<<(ostream &os, const Fraction &a) {
  if (a.isInf()) {
    os << "Inf";
  } else if (a.numerator == 0) {
    os << "0";
  } else {
    bool neg = a.numerator < 0;
    if (neg) {
      os << "(";
    }
    long n = a.numerator;
    long d = a.denominator;
    long q = n / d;
    long r = n % d;
    bool zs = false;
    if (q != 0) {
      os << q;
      zs = true;
    }
    if (r != 0) {
      if (zs) os << " ";
      os << (zs ? labs(r) : r) << "/" << d;
    }
    if (neg) {
      os << ")";
    }
  }
  return os;
}

Fraction operator+(const Fraction &a, const Fraction &b) {
  Fraction r = a;
  r += b;
  return r;
}
Fraction operator-(const Fraction &a, const Fraction &b) {
  Fraction r = a;
  r -= b;
  return r;
}
Fraction operator*(const Fraction &a, const Fraction &b) {
  Fraction r = a;
  r *= b;
  return r;
}
Fraction operator/(const Fraction &a, const Fraction &b) {
  Fraction r = a;
  r /= b;
  return r;
}

int main() {
  long a1, b1, a2, b2;
  scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
  Fraction a = Fraction(a1, b1);
  Fraction b = Fraction(a2, b2);
  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;
  return 0;
}

