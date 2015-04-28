#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1005

char zoj[MAXN];
int z, j, n, f;
int cntz, cntj;

int main() {
	while (scanf("%s", zoj) == 1) {
		cntz = cntj = f = 0;
		n = strlen(zoj);
		for (int i = 0; i < n; ++i) {
			if (zoj[i] == 'z') { z = i; ++cntz; }
			if (zoj[i] == 'j') { j = i; ++cntj; }
			if (zoj[i] != 'z' && zoj[i] != 'o' && zoj[i] != 'j') { f = 1; }
		}
		if (f || cntz != 1 || cntj != 1) {
			printf("Wrong Answer\n");
		} else {
			int l = z, m = j - (z + 1), r = n - (j + 1);
			(m * l == r && m > 0) ? printf("Accepted\n") : printf("Wrong Answer\n");
		}
	}
	return 0;
}
