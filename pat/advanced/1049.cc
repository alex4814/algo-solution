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
	int r = 0;
	int m = 0;
	int b = 1;	// base of 10
	while (n > 0) {
		int x = n % 10;
		r += n / 10 * b;
		if (x == 1) {
			r += m + 1;
		} else if (x > 1) {
			r += b;
		}
		n /= 10;
		m += x * b;
		b *= 10;
	}
	printf("%d\n", r);
	return 0;
}


