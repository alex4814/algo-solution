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
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int check(ll a, ll b) {
	if (a % b == 0) return 1;
	ll q = a / b, r = a - q * b;
	return q == 1 ? check(b, r) ^ 1 : 1;
}

int main() {
	ll a, b;

	while (scanf("%lld %lld", &a, &b) == 2) {
		if (a == 0 && b == 0) break;
		if (a < b) a ^= b, b ^= a, a ^= b; 
		puts(a / b > 1 || check(a, b) ? "Stan wins" : "Ollie wins");
	}

	return 0;
}


