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

int jcnt[3], ycnt[3];
int jr[3], yr[3];	// 0 for lose, 1 for draw, 2 for win
int ix[256];
char ltr[] = "BCJ";

int outcome(char a, char b) {
	if (a == b) return 0;
	if (a == 'B' && b == 'C') return 1;
	if (a == 'C' && b == 'J') return 1;
	if (a == 'J' && b == 'B') return 1;
	return -1;
}

void print_max(int *d, char o) {
	int mx = -1, k = -1;
	for (int i = 0; i < 3; ++i) {
		if (mx < d[i]) mx = d[k = i];
	}
	printf("%c%c", ltr[k], o);
}

int main() {
	ix['B'] = 0, ix['C'] = 1, ix['J'] = 2;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char a[2], b[2];
		scanf("%s %s", a, b);
		int oc = outcome(a[0], b[0]);
		jr[ oc + 1 ] += 1;
		yr[ -oc + 1 ] += 1;
		if (oc == 1) jcnt[ ix[a[0]] ] += 1; 
		if (oc == -1) ycnt[ ix[b[0]] ] += 1;
	}
	printf("%d %d %d\n", jr[2], jr[1], jr[0]);
	printf("%d %d %d\n", yr[2], yr[1], yr[0]);
	print_max(jcnt, ' ');
	print_max(ycnt, '\n');
	return 0;
}


