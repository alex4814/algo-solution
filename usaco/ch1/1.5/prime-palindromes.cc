/*
ID: alex4814
PROG: pprime
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

int a, b;
int ten[] = { 1, 10, 100, 1000, 10000, 100000 };
vector<int> ret;

inline int length(int x) {
	int ret = 0;
	while (x > 0) {
		x /= 10; ++ret;
	}
	return ret;
}

int make_palindrome(int f, int opt) {
	int l = length(f);
	int d[10], k = (opt ? l - 1 : l);
	int x = f, q = 0;

	while (x > 0) {
		d[k + q++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < l; ++i) {
		d[l - 1 - i] = d[k + i];
	}

	int ret = 0;
	for (int i = 0; i < 2 * l - opt; ++i) {
		ret = ret * 10 + d[i];
	}
	return ret;
}

bool is_prime(int n) {
	int x = sqrt(n);
	for (int i = 2; i <= x; ++i) {
		if (n % i == 0) { return false; }
	}
	return true;
}

int main() {
#ifdef FILEIO
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
#endif

	scanf("%d %d", &a, &b);
	int lb = length(b);

	for (int f = 1; f < ten[ (lb + 1) / 2 ]; ++f) {
		int p1 = make_palindrome(f, 0);
		if (a <= p1 && p1 <= b && is_prime(p1)) {
			ret.push_back(p1);
		}
		int p2 = make_palindrome(f, 1);
		if (a <= p2 && p2 <= b && is_prime(p2)) {
			ret.push_back(p2);
		}
	}

	sort(ret.begin(), ret.end());
	int sz = ret.size();
	for (int i = 0; i < sz; ++i) {
		printf("%d\n", ret[i]);
	}
	return 0;
}
