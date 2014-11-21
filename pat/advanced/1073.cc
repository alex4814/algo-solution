#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define EPS 1e-8
#define MAXN 10005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

char sf;
char ws[MAXN];
int e;

int main() {
	char sf = getchar();
	int n = 0;
	char c;
	while ((c = getchar()) != 'E') {
		ws[n++] = c;
	}
	scanf("%d", &e);
	if (sf == '-') {
		putchar(sf);
	}
	int dot = n;
	for (int i = 0; i < n; ++i) {
		if (ws[i] == '.') {
			dot = i; break;
		}
	}
	if (dot == n) {
		ws[n++] = '.';
	}
	if (dot + e <= 0) {
		putchar('0');
		putchar('.');
		for (int i = 0; i < -(dot + e); ++i) {
			putchar('0');
		}
		for (int i = 0; i < n; ++i) {
			if (ws[i] == '.') continue;
			putchar(ws[i]);
		}
	} else if (dot + e < n - 1) {
		for (int i = 0; i < e; ++i) {
			swap(ws[dot + i], ws[dot + i + 1]);
		}
		for (int i = 0; i < n; ++i) {
			putchar(ws[i]);
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (ws[i] == '.') continue;
			putchar(ws[i]);
		}
		for (int i = n; i <= (dot + e); ++i) {
			putchar('0');
		}
	}
	putchar('\n');
	return 0;
}

