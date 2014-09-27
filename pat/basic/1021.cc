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

char s[MAXN];
int cnt[10];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		cnt[ s[i] - '0' ]++;
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i]) {
			printf("%d:%d\n", i, cnt[i]);
		}
	}
	return 0;
}


