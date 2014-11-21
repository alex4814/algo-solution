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

const int yi = 100000000;
const int wan = 10000;

vector<string> digit = {
	" ling", " yi", " er", " san", " si", " wu", " liu", " qi", " ba", " jiu"
};
string ret;

void print(int n, bool s) {
	if (!n && !s) ret += digit[0];
	if (!n) return;

	int d[4] = { 0, 0, 0, 0 };
	vector<string> dw = { "", " Shi", " Bai", " Qian" };
	int k = 0;
	while (n > 0) {
		d[k++] = n % 10;
		n /= 10;
	}
	int i = 3;	// leading zeros, upper bound
	if (d[i] == 0) {
		if (s) ret += digit[0];
		while (d[--i] == 0);
	}
	int j = -1;	// trailing zeros, lower bound
	while (d[++j] == 0);
	for (k = i; k >= j; --k) {
		if (d[k] == 0) {
			if (d[k + 1] == 0) continue;
			ret += digit[0];
		} else {
			ret += digit[ d[k] ] + dw[k];
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	if (n == 0) {
		puts("ling");
		return 0;
	}
	if (n < 0) {
		n = -n;
		printf("Fu ");
	}
	bool start = false;
	if (n >= yi) {
		print(n / yi, start);
		start = true;
		n %= yi;
		ret += " Yi";
	}
	if (n >= wan) {
		print(n / wan, start);
		start = true;
		n %= wan;
		ret += " Wan";
	}
	print(n, start);
	printf("%s\n", ret.c_str() + 1);
	return 0;
}


