#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXI 5

typedef pair<int, int> pii;
typedef long long ll;

map<string, set<int>> q[MAXI];
string s;

int main() {
	int n;
	cin >> n;
	for (int i = 0, id; i < n; ++i) {
		cin >> id; getchar();
		for (int k = 0; k < MAXI; ++k) {
			getline(cin, s);
			if (k == 2) {	// keywords
				size_t cur = 0, p;
				while ((p = s.find_first_of(' ', cur)) != string::npos) {
					q[k][s.substr(cur, p - cur)].insert(id);
					cur = p + 1;
				}
				if (cur < s.size()) {
					q[k][s.substr(cur)].insert(id);
				}
			} else {
				q[k][s].insert(id);
			}
		}
	}
	cin >> n; getchar();
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		int tp = s[0] - '0' - 1;
		cout << s << endl;
		s = s.substr(3);
		for (auto &x: q[tp][s]) {
			printf("%07d\n", x);
		}
		if (q[tp][s].size() == 0) {
			printf("Not Found\n");
		}
	}
	return 0;
}


