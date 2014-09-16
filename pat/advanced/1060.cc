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
string n1, n2;

int dot_pos(string s) {
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '.') return i;
	}
	return -1;
}
int start_pos(string s) {
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] != '.' && s[i] != '0') return i;
	}
	return -1;
}

string to_standard(string s) {
	string ret = "0.";
	int dot = dot_pos(s);
	int start = start_pos(s);
	int len = s.size();
	if (start == -1) {
		ret.append(n, '0'); 
		ret.append("*10^0");
	} else {
		int m = n - (len - start);
		m += (start < dot ? 1 : 0);
		if (m > 0) s.append(m, '0');
		if (dot == -1) {
			ret += s.substr(start, n);
			ret += "*10^" + to_string(len - start);
		} else {
			if (start < dot) {
				if (dot - start < n) {
					ret += s.substr(start, dot - start);
					ret += s.substr(dot + 1, n - (dot - start));
				} else {
					ret += s.substr(start, n);
				}
				ret += "*10^" + to_string(dot - start);
			} else {
				ret += s.substr(start, n);
				ret += "*10^" + to_string(-(start - dot - 1));
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> n1 >> n2;

	n1 = to_standard(n1);
	n2 = to_standard(n2);
	if (n1 == n2) {
		cout << "YES " << n1 << endl;
	} else {
		cout << "NO " << n1 + " " << n2 << endl;
	}
	return 0;
}


