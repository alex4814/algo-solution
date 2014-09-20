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
#define MAXN 16000005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int n, nc;
char text[MAXN];
bool shown[MAXN];
int m[256];

int main() {
	scanf("%d %d %s", &n, &nc, text);

	memset(m, -1, sizeof(m));
	int len = strlen(text);
	for (int i = 0, t = 0; i < len; ++i) {
		if (m[ text[i] ] == -1) {
			m[ text[i] ] = t++;
		}
	}

	int weight = 1;
	for (int i = 1; i < n; ++i) {
		weight = weight * nc;
	}
	int hash = 0;
	for (int i = 0; i < n; ++i) {
		hash = hash * nc + m[ text[i] ];
	}

	shown[hash] = true;
	int ret = 1;
	for (int i = n; i < len; ++i) {
		hash = (hash - m[ text[i - n] ] * weight) * nc + m[ text[i] ];
		if (!shown[hash]) {
			shown[hash] = true;
			ret++;
		}
	}
	printf("%d\n", ret);

	return 0;
}


