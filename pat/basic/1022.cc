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
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

void print(int x, int p) {
	if (x == 0) {
		printf("0\n");
		return;
	}
	int d[MAXN], n = 0;
	while (x > 0) {
		d[n++] = x % p;
		x /= p;
	}
	for (int i = n - 1; ~i; --i) {
		putchar(d[i] + '0');
	}
	putchar('\n');
}

int main() {
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	print(a + b, d);
	return 0;
}


