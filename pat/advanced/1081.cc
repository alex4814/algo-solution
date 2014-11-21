#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 105
#define MAXL 85

typedef pair<int, int> pii;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct Rational {
	ll n, d;

	void reduce() {
		int g = gcd(n, d);
		n /= g;
		d /= g;
	}
	
	Rational operator + (const Rational &b) const {
		Rational r = { 0, 0 };
		r.n = n * b.d + d * b.n;
		r.d = d * b.d;
		r.reduce();
		return r;
	}

	void print() {
		int i_part = n / d;
		n = n % d;
		if (i_part || !n) printf("%d", i_part);
		if (i_part && n) putchar(' ');
		if (n) printf("%lld/%lld", n, d);
		putchar('\n');
	}
};

Rational r[MAXN];
char s[MAXL];

int main() {
	int n;
	scanf("%d", &n);
	Rational sum = { 0, 1 };
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		sscanf(s, "%lld/%lld", &r[i].n, &r[i].d);
		sum = sum + r[i];
	}
	sum.print();
	return 0;
}


