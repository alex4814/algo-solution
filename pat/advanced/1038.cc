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
#define MAXN 10005
#define MAXL 9

typedef pair<int, int> pii;
typedef long long ll;

struct Number {
	char rn[MAXL];
	char cn[MAXL];
	void build_compare_number() {
		int n = strlen(rn);
		strcpy(cn, rn);
		int m = n, i = 0;
		while (m < MAXL - 1) {
			cn[m++] = rn[i++ % n];
		}
		cn[m] = '\0';
	}
	bool operator < (const Number &b) const {
		return strcmp(cn, b.cn) < 0;
	}
};

Number nb[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", nb[i].rn);
		nb[i].build_compare_number();
	}
	sort(nb, nb + n);
	bool start = false;
	for (int i = 0; i < n; ++i) {
		int sz = strlen(nb[i].rn);
		for (int j = 0; j < sz; ++j) {
			if (start) {
				putchar(nb[i].rn[j]);
			} else if (nb[i].rn[j] != '0') {
				putchar(nb[i].rn[j]);
				start = true;
			}
		}
	}
	if (!start) {
		putchar('0');
	}
	putchar('\n');
	return 0;
}


