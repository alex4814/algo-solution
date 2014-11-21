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

int p[MAXN], np;
bool f[MAXN];

void get_primes(int n) {
	np = 0;
	for (int i = 2; i < n; ++i) {
		if (!f[i]) { 
			p[np++] = i;
	 	}
		for (int j = 0; j < np && p[j] * i < n; ++j) {
			f[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

vector<pii> r;

int main() {
	long long n, m;
	scanf("%lld", &n);
	m = n;
	if (n == 1) {
		printf("1=1\n");
		return 0;
	}
	get_primes(MAXN);
	for (int i = 0; i < np; ++i) {
		int c = 0;
		while (n % p[i] == 0) {
			c += 1;
			n /= p[i];
		}
		if (c) {
			r.push_back(make_pair(p[i], c));
		}
	}
	if (n > 1) {
		r.push_back(make_pair(n, 1));
	}
	printf("%lld=", m);
	int sz = r.size();
	for (int i = 0; i < sz; ++i) {
		if (i) {
			putchar('*');
		}
		printf("%d", r[i].first);
		if (r[i].second > 1) {
			printf("^%d", r[i].second);
		}
	}
	putchar('\n');
	return 0;
}


