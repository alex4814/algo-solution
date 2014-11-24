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
#define MAXM 10005

typedef pair<int, int> pii;
typedef long long ll;

int b[MAXN];
int cnt[MAXM];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
		cnt[ b[i] ] += 1;
	}
	for (int i = 0; i < n; ++i) {
		if (cnt[ b[i] ] == 1) {
			printf("%d\n", b[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}


