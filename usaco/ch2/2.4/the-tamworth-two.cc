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
#define MAXN 15
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

const int n = 10;
int g[MAXN][MAXN];
int v[2][MAXN][MAXN][4];
int fx, fy;
int cx, cy;

inline bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int walk(int x, int y, int d, int p) {
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	int timestamp = 1;
	while (true) {
		int tx = x + dx[d];
		int ty = y + dy[d];
		if (!valid(tx, ty) || g[tx][ty]) {
			d = (d + 1) % 4;
			tx = x;
			ty = y;
		}
		if (p) printf("C: %d %d %d, %d\n", tx, ty, d, timestamp);
		else printf("F: %d %d %d, %d\n", tx, ty, d, timestamp);
		if (v[p][tx][ty][d]) {
			break;
		}
		v[p][x = tx][y = ty][d] = timestamp++;
	}
	return timestamp;
}

int work() {
	int r = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int d1 = 0; d1 < 4; ++d1) {
				if (v[0][i][j][d1] == 0) {
					continue;
				} 
				for (int d2 = 0; d2 < 4; ++d2) {
					if (x == v[1][i][j][d2]) {
						return x;
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	char s[MAXN];
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		for (int j = 0; j < n; ++j) {
			if (s[j] == 'F') {
				fx = i, fy = j;
			} else if (s[j] == 'C') {
				cx = i, cy = j;
			} else {
				g[i][j] = (s[j] == '*');
			}
		}
	}
	walk(fx, fy, 0, 0);
	walk(cx, cy, 0, 1);
	printf("%d\n", work());
	return 0;
}


