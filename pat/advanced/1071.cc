#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 1050005
#define MAXL 1005

typedef pair<int, int> pii;
typedef long long ll;

char w[MAXN];
map<string, int> m;

int main() {
	int c;
	int n = 0;
	while ((c = getchar()) != '\n') {
		if (isalnum(c)) {
			if (isalpha(c)) {
				c = tolower(c);
			}
			w[n++] = c;
		} else if (n) {
			w[n] = '\0';
			string s(w);
			m[s] += 1;
			n = 0;
		}
	}
	if (n) {
		w[n] = '\0';
		string s(w);
		m[s] += 1;
	}
	string rs;
	int r = 0;
	for (const auto& item: m) {
		if (item.second > r) {
			r = item.second;
			rs = item.first;
		} else if (item.second == r) {
			if (item.first > rs) {
				rs = item.first;
			}
		}
	}
	printf("%s %d\n", rs.c_str(), r);
	return 0;
}


