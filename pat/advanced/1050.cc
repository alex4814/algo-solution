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
#define MAXN 10005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

char s1[MAXN], s2[MAXN];

int main() {
	fgets(s1, MAXN, stdin);
	fgets(s2, MAXN, stdin);
	int n = strlen(s2) - 1;
	sort(s2, s2 + n);
	int n1 = strlen(s1);
	int n2 = unique(s2, s2 + n) - s2;
	for (int i = 0; i < n1 - 1; ++i) {
		if (!binary_search(s2, s2 + n2, s1[i])) {
			putchar(s1[i]);
		}
	}
	putchar('\n');
	return 0;
}


