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

int T;
ll N;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%lld", &N);
		puts(miller_rabin(N, nIter) ? "Prime"
	}

	return 0;
}


