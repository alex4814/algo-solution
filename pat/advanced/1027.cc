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
#define RADIX 13

typedef pair<int, int> pii;
typedef long long ll;

int main() {
	const char rep[] = "0123456789ABC";
	putchar('#');
	for (int i = 0, c; i < 3; ++i) {
		scanf("%d", &c);
		putchar(rep[ c / RADIX ]);
		putchar(rep[ c % RADIX ]);
	}
	putchar('\n');
	return 0;
}


