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
#define MAXL 25

typedef pair<int, int> pii;
typedef long long ll;

string str_double(string a) {
	int d[MAXL];
	int sz = a.size();
	for (int i = sz - 1; i >= 0; --i) {
		d[sz - 1 - i] = 2 * (a[i] - '0');
	}
	bool cf = false;
	for (int i = 0; i < sz; ++i) {
		if (d[i] >= 10) {
			d[i + 1] += 1;
			d[i] -= 10;
			if (i == sz - 1) {
				cf = true;
			}
		}
	}
	string b = (cf ? "1" : "");
	for (int i = sz - 1; i >= 0; --i) {
		b += d[i] + '0';
	}
	return b;
}

bool same_count(string a, string b) {
	int d[10];
	memset(d, 0, sizeof(d));
	int sz = a.size();
	for (int i = 0; i < sz; ++i) {
		d[a[i] - '0'] += 1;
	}
	sz = b.size();
	for (int i = 0; i < sz; ++i) {
		d[b[i] - '0'] -= 1;
	}
	for (int i = 0; i < 10; ++i) {
		if (d[i] != 0) return false;
	}
	return true;
}

int main() {
	string a;
	cin >> a;
	string b = str_double(a);
	if (same_count(a, b)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	cout << b << endl;
	return 0;
}


