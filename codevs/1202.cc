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

int main() {
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		sum += x;
	}
	printf("%lld\n", sum);
	return 0;
}


