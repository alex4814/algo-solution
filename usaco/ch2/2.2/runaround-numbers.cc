/*
ID: alex4814
LANG: C++
TASK: runround
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
#define MAXN 55
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

#define FILEIO

int m;
char t[10];
char dig[10], vis[10];

bool is_runaround() {
	int n = strlen(dig);
	int c = 0;
	memset(t, 0, sizeof(t));
	do {
		c = (c + dig[c] - '0') % n;
		if (t[c]) return false;
		t[c] = 1;
	} while (c != 0);
	for (int i = 0; i < n; ++i) {
		if (t[i] != 1) return false;
	}
	return true;
}

// generate md-digit number
// with current nd digits
// stored in *dig*, using *vis*
void permutation(int nd, int md) {
	if (nd == md) {
		dig[nd] = '\0';
		int x; sscanf(dig, "%d", &x);
		if (x > m && is_runaround()) {
			printf("%d\n", x);
			exit(0);
		}
	} else {
		for (int i = 1; i <= 9; ++i) {
			if (!vis[i]) {
				vis[i] = 1;
				dig[nd] = i + '0';
				permutation(nd + 1, md);
				vis[i] = 0;
			}
		}
	}
}

int main() {
#ifdef FILEIO
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
#endif

	scanf("%d", &m);
	for (int i = 1; i <= 9; ++i) {
		permutation(0, i);
	}

	return 0;
}


