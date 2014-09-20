/*
ID: alex4814
LANG: C++
TASK: preface
*/

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

#define FILEIO

char *rn = "IVXLCDM";
int cnt[256];

char *s[] = {
	"...", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
	"...", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
	"...", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
	"...", "M", "MM", "MMM",
};

int n;

void count(int x) {
	int d[4], nd = 0;
	while (x > 0) {
		d[nd++] = x % 10;
		x /= 10;
	}
	for (int i = 0, ix; i < nd; ++i) {
		ix = i * 10 + d[i];
		int len = strlen(s[ix]);
		for (int j = 0; j < len; ++j) {
			cnt[ s[ix][j] ]++;
		}
	}
}

int main() {
#ifdef FILEIO
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		count(i);
	}
	int m = 0;
	for (int i = 0; i < 7; ++i) {
		if (cnt[ rn[i] ] != 0) m = i + 1;
	}
	for (int i = 0; i < m; ++i) {
		printf("%c %d\n", rn[i], cnt[ rn[i] ]);
	}

	return 0;
}


