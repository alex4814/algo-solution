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

int max_width(int n) {
	int x = 1;
	while ((x + 3) * (x - 1) < 2 * n) {
		x += 2;
	}
	return x - 2;
}

void print_line(int w, int sp, char d) {
	for (int i = 0; i < sp; ++i) putchar(' ');
	for (int i = 0; i < w; ++i) putchar(d);
	putchar('\n');
}

void print(int w, int sp, char d) {
	if (w < 1) return;
	if (w == 1) {
		print_line(w, sp, d);
		return;
	}
	print_line(w, sp, d);
	print(w - 2, sp + 1, d);
	print_line(w, sp, d);
}

int main() {
	int n;
	char d[2];
	scanf("%d %s", &n, d);
	int w = max_width(n);
	print(w, 0, d[0]);
	printf("%d\n", n - 1 - (w + 3) * (w - 1) / 2);
	return 0;
}


