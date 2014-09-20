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

int T, n;
char pn[15];
int tr[MAXN][10];
bool we[MAXN];

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(tr, 0, sizeof(tr));
		memset(we, 0, sizeof(we));
		scanf("%d", &n);
		bool yes = true;
		int tn = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", pn);
			if (!yes) continue;
			int len = strlen(pn);
			int p = 0, nn = 0;
			for (int j = 0; j < len; ++j) {
				if (we[p]) { yes = false; break; }
				if (!tr[p][ pn[j] - '0' ]) tr[p][ pn[j] - '0' ] = nn = ++tn;
				p = tr[p][ pn[j] - '0' ];
			}
			we[p] = true;
			if (!nn) yes = false;
		}
		puts(yes ? "YES" : "NO");
	}
	return 0;
}
