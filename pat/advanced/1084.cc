#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 105
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

char a[MAXN], b[MAXN];
bool in[256];

int main() {
	scanf("%s %s", a, b);
	int na = strlen(a);
	int nb = strlen(b);
	int i = 0, j = 0;
	while (i < na && j < nb) {
		a[i] = toupper(a[i]);
		b[j] = toupper(b[j]);
		if (a[i] != b[j]) {
			if (!in[ a[i] ]) putchar(a[i]);
			in[ a[i] ] = true;
		} else {
			j++;
		}
		i++;
	}
	for (int k = i; k < na; ++k) {
		a[k] = toupper(a[k]);
		if (!in[ a[k] ]) putchar(a[k]);
	}
	putchar('\n');
	return 0;
}

