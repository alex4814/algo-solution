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

char s[MAXN];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int n1 = (n + 2) / 3 - 1;
	int n2 = n - n1 - n1;
	for (int i = 0; i < n1; ++i) {
		putchar(s[i]);
		for (int j = 0; j < n2 - 2; ++j) {
			putchar(' ');
		}
		putchar(s[n - 1 - i]);
		putchar('\n');
	}
	for (int i = 0; i < n2; ++i) {
		putchar(s[n1 + i]);
	}
	putchar('\n');
	return 0;
}


