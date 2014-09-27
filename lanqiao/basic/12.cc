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

int n;
char x[MAXN], o[MAXN << 2];
char t[256][5];

void print() {
	int len = strlen(x), n = 0;
	for (int i = len - 1; i >= 0; --i) {
		
	}
}

void init() {
	t['0'] = "0000";
	t['1'] = "0001";
	t['2'] = "0010";
	t['3'] = "0011";
	t['4'] = "0100";
	t['5'] = "0101";
	t['6'] = "0110";
	t['7'] = "0111";
	t['8'] = "1000";
	t['9'] = "1001";
	t['A'] = "1010";
	t['B'] = "1011";
	t['C'] = "1100";
	t['D'] = "1101";
	t['E'] = "1110";
	t['F'] = "1111";
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", x);
		print();
	}
	return 0;
}


