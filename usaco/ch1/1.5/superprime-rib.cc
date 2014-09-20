/*
ID: alex4814
PROG: sprime
LANG: C++
*/

#define NDEBUG
#define FILEIO

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 100005
#define EPS 1e-8
#define INF 0x3f3f3f3f

int n;

bool is_prime(int n) {
	int x = sqrt(n);
	for (int i = 2; i <= x; ++i) {
		if (n % i == 0) { return false; }
	}
	return true;
}

void dfs(int x, int l) {
	if (l == n) {
		printf("%d\n", x);
		return;
	}
	for (int i = 1; i < 10; i += 2) {
		if (is_prime(x * 10 + i)) {
			dfs(x * 10 + i, l + 1);
		}
	}
}
int main() {
#ifdef FILEIO
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
#endif

	scanf("%d", &n);

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}
