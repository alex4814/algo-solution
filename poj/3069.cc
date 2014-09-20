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

int R, n;
int p[MAXN];

int main() {
	while (scanf("%d %d", &R, &n)) {
		if (R == -1 && n == -1) break;	
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
		}
		sort(p, p + n);
	}
	
	return 0;
}


