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

int main() {
	fgets(s, MAXN, stdin);
	int n = strlen(s) - 1;
	int r = 0;
	for (int i = 0; i < n; ++i) {
		for (int tr = 0; i - tr >= 0 && i + tr < n; ++tr) {
			if (s[i - tr] == s[i + tr]) {
				r = max(r, 2 * tr + 1);
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int tr = 0; i - tr >= 0 && i + 1 + tr < n; ++tr) {
			if (s[i - tr] == s[i + 1 + tr]) {
				r = max(r, 2 * tr + 2);
			} else {
				break;
			}
		}
	}
	printf("%d\n", r);
	return 0;
}


