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
#define MAXN 20005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

bool is_prime(int n) {
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	int x = sqrt(n);
	for (int i = 2; i <= x; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int revise(int n) {
	int r = n - 1;
	while (!is_prime(++r));
	return r;
}

bool ht[MAXN];

int hashing(int x, int sz) {
	int t = 0;
	int hk = x % sz;
	while (t++ < sz) {
		if (ht[hk] == false) {
			ht[hk] = true;
			return hk;
		}
		hk = (x + t * t) % sz;
	}
	return -1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	n = revise(n);
	for (int i = 0, x; i < m; ++i) {
		scanf("%d", &x);
		int h = hashing(x, n);
		h == -1 ? putchar('-') : printf("%d", h);
		putchar(i + 1 == m ? '\n' : ' ');
	}
	return 0;
}


