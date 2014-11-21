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

vector<string> s;

int main() {
	string word;
	while (cin >> word) {
		s.push_back(word);
	}
	int sz = s.size();
	for (int i = sz - 1; i >= 0; --i) {
		cout << s[i] << (i == 0 ? '\n' : ' ');
	}
	return 0;
}


