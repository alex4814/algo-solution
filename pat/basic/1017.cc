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
#define MAXN 1005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

char a[MAXN];
char q[MAXN];
int r;

char *divide(char *x, int y) {
	int n = strlen(x), m = 0;
	for (int i = 0; i < n; ++i) {
		r = r * 10 + (x[i] - '0');
		if (r >= y) {
			q[m++] = r / y + '0';
			r = r % y;
		} else {
			q[m++] = '0';
		}
	}
	q[m] = '\0';
	for (int i = 0; i < m; ++i) {
		if (q[i] != '0') return q + i;
	}
	return q;
}

int main() {
	int b;
	scanf("%s %d", a, &b);
	char *p = divide(a, b);
	printf("%s %d\n", p, r);
	return 0;
}


