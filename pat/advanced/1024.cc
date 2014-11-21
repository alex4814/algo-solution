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
#define MAXN 1005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

string reverse(string n) {
	string r;
	int sz = n.size();
	for (int i = sz - 1; i >= 0; --i) {
		r += n[i];
	}
	return r;
}

bool is_palindromic(string n) {
	int sz = n.size();
	for (int i = 0; i < sz; ++i) {
		if (n[i] != n[sz - 1 - i]) {
			return false;
		}
	}
	return true;
}

string add(string a, string b) {
	static int d[MAXN];
	fill(d, d + MAXN, 0);
	int asz, bsz, n;
	asz = a.size();
	for (int i = asz - 1; i >= 0; --i) {
		d[asz - 1 - i] += a[i] - '0';
	}
	bsz = b.size();
	for (int i = bsz - 1; i >= 0; --i) {
		d[bsz - 1 - i] += b[i] - '0';
	}
	bool cf = false;
	n = max(asz, bsz);
	for (int i = 0; i < n; ++i) {
		if (d[i] >= 10) {
			d[i + 1] += 1;
			d[i] -= 10;
			if (i + 1 == n) {
				cf = true;
			}
		}
	}
	string r = (cf ? "1" : "");
	for (int i = n - 1; i >= 0; --i) {
		r += d[i] + '0';
	}
	return r;
}

int main() {
	string n;
	int k;
	cin >> n >> k;
	int iter = 0;
	while (!is_palindromic(n) && iter++ < k) {
		n = add(n, reverse(n));
	}
	cout << n << endl;
	cout << min(iter, k) << endl;
	return 0;
}


