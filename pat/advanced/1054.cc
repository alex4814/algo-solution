#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

map<int, int> d;

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	n = m * n;
	for (int i = 0; i < n; ++i) {
		ll color;
		scanf("%d", &color);
		d[color] += 1;
	}
  int	r = 0, max_cnt = 0;
	for (auto& x: d) {
		if (x.second > max_cnt) {
			r = x.first;
			max_cnt = x.second;
		}
	}
	printf("%d\n", r);
	return 0;
}


