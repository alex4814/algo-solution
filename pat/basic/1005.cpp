#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define _N 10005
#define _M 105
#define PI acos(-1.0)

int n;
int in[_N], covered[_N];

void cover(int x) {
	while (x > 1) {
		x & 1 ? x = (3 * x + 1) / 2 : x /= 2;
		covered[x] = 1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0, a; i < n; ++i) {
		scanf("%d", &a);
		in[a] = 1;
		cover(a);
	}
	vector<int> ret;
	for (int i = 0; i < _N; ++i) if (in[i]) {
		if (!covered[i]) {
			ret.push_back(i);
		}
	}
	int m = ret.size();
	printf("%d", ret[m - 1]);
	for (int i = m - 2; ~i; --i) {
		printf(" %d", ret[i]);
	}
	printf("\n");
	return 0;
}
