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

int d[10];

int main() {
	int k = 0;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", d + i);
		if (!k && i && d[i]) d[k = i]--;
	}
	putchar(k + '0');
	for (int i = 0; i < 10; ++i) {
		while (d[i]--) {
			putchar(i + '0');
		}
	}
	putchar('\n');
	return 0;
}


