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
	long double a, b, c;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b >> c;
		printf("Case #%d: ", i);
		puts(a + b > c ? "true" : "false");
	}
	return 0;
}


