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
#define MAXL 15

typedef pair<int, int> pii;
typedef long long ll;

char name[MAXN][MAXL];
char pwd[MAXN][MAXL];
vector<int> modified;

bool need_modifiy(char *s) {
	int n = strlen(s);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			s[i] = '@';
		} else if (s[i] == '0') {
			s[i] = '%';
		} else if (s[i] == 'l') {
			s[i] = 'L';
		} else if (s[i] == 'O') {
			s[i] = 'o';
		} else {
			cnt += 1;
		}
	}
	return cnt != n;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", name[i], pwd[i]);
		if (need_modifiy(pwd[i])) {
			modified.push_back(i);
		}
	}
	int sz = modified.size();
	if (sz == 0) {
		if (n == 1) {
			printf("There is 1 account and no account is modified\n");
		} else {
			printf("There are %d accounts and no account is modified\n", n);
		}
	} else {
		printf("%d\n", sz);
		for (int i = 0; i < sz; ++i) {
			int x = modified[i];
			printf("%s %s\n", name[x], pwd[x]);
		}
	}
	return 0;
}


