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
#define MAXN 1000005
#define MAXM 105

typedef long long ll;
int n1, n2, p1, p2;
ll a[MAXN], b[MAXN], ret;

int main() {
	scanf("%d", &n1);
	for (int i = 0; i < n1; ++i) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; ++i) {
		scanf("%lld", &b[i]);
	}
	int i = 0, j = 0, cnt = 0;
	while (cnt <= (n1 + n2 - 1) / 2) {
		if (i < n1 && j < n2) {
			if (a[i] <= b[j]) {
				ret = a[i++];
			} else {
				ret = b[j++];
			}
		} else if (i < n1) {
			ret = a[i++];
		} else if (j < n2) {
			ret = b[j++];
		}
		++cnt;
	}
	cout << ret << endl;
	return 0;
}
