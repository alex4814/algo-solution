#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 100005
#define MAXM 105

void print(int x) {
	if (x == 0) {
		printf("0\n");
		return;
	}
	int d[10] = {0}, n = 0;
	bool f = x < 0 ? true : false;

	x = abs(x);
	while (x > 0) {
		d[n++] = x % 10;
		x /= 10;
	}
	f ? printf("-") : 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i != n - 1 && i % 3 == 2) { printf(","); }
		printf("%d", d[i]);
	}
	printf("\n");
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	print(a + b);
	return 0;
}
