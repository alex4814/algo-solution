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
	if (n % 1111 == 0) {
		printf("%04d - %04d = 0000\n", n, n);
		return 0;
	} 
	int a, b;
	char x[5], y[5];
	do {
		sprintf(y, "%04d", n);
		sort(y, y + 4);
		for (int i = 0; i < 4; ++i) {
			x[i] = y[3 - i];
		}
		x[4] = y[4] = '\0';
		sscanf(x, "%d", &a);
		sscanf(y, "%d", &b);
		n = a - b;
		printf("%04d - %04d = %04d\n", a, b, n);
	} while (n != 6174);
	return 0;
}


