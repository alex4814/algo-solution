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
#define MAXN 54
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int s[MAXN];
int p[MAXN];
char cards[MAXN][5] = {
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
	"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
	"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
	"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
	"J1", "J2"
};

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < MAXN; ++i) {
		scanf("%d", s + i);
		s[i] -= 1;
	}
	for (int i = 0; i < MAXN; ++i) {
		int x = i;
		for (int j = 0; j < k; ++j) {
			x = s[x];
		}
		p[x] = i;
	}
	for (int i = 0; i < MAXN; ++i) {
		printf("%s%c", cards[ p[i] ], i + 1 == MAXN ? '\n' : ' ');
	}
	return 0;
}


