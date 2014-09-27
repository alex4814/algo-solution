#include <cstdio>
#include <string>
using namespace std;

#define MAXN 205

string s;

bool symmetric(int ix, int n) {
	for (int i = 0; i < n; ++i) {
		if (s[ix + i] != s[ix + n - 1 - i]) return false;
	}
	return true;
}

int i, n, f;

int main() {
	while (cin >> s && s != "#") {
		n = s.size();
		s += s;

		f = 0;
		for (i = 0; i < n; ++i) {
			if (symmetric(i, n)) {
				f = 1; break;
			}
		}
		f ? printf("YES %d\n", (i + n / 2) % n) : printf("NO\n");
	}
	return 0;
}
