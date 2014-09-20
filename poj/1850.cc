#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

ll f[26][11];
ll tot[11];
char word[11];
int n;

inline bool in_order() {
	for (int i = 1; i < n; ++i) {
		if (word[i - 1] >= word[i]) return false;
	}
	return true;
}

ll cal(int c, int l) {
	ll ret = 0;
	for (int len = 1; len <= l; ++len) {
		for (int chr = 0; chr < 26; ++chr) {
			if (chr == c && len == l) break;
			ret += f[chr][len];
		}
	}
	return ret;
}

int main() {
	scanf("%s", word);
	n = strlen(word);
	if (in_order()) {
		for (int i = 0; i < 26; ++i) {
			f[i][0] = 0, f[i][1] = 1;
		}
		for (int l = 2; l <= n; ++l) {
			for (int c = 0; c < 26; ++c) {
				f[c][l] = 0;
				for (int _c = c + 1; _c < 26; ++_c) {
					f[c][l] += f[_c][l - 1];
				}
			}
		}

		ll ret = cal(word[0] - 'a', n);
		for (int i = 1; i < n; ++i) {
			for (int chr = word[i - 1] - 'a' + 1; chr < word[i] - 'a'; ++chr) {
				ret += f[chr][n - i];
			}
		}
		printf("%lld\n", ret + 1);
	} else {
		printf("0\n");
	}

	return 0;
}
