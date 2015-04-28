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
#define MAXN 10 * 26 * 26 * 26
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

vector<int> stu[MAXN];

int hash_name(char *s) {
	int r = 0;
	for (int i = 0; i < 3; ++i) {
		r = r * 26 + s[i] - 'A';
	}
	r = r * 10 + s[3];
	return r;
}


int main() {
	int n, k;
	char name[5];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int cid, rn;
		scanf("%d %d", &cid, &rn);
		for (int j = 0; j < rn; ++j) {
			scanf("%s", name);
			int h = hash_name(name);
			stu[h].push_back(cid);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", name);
		int h = hash_name(name);
		int sz = stu[h].size();
		printf("%s %d", name, sz);
		sort(stu[h].begin(), stu[h].end());
		for (int j = 0; j < sz; ++j) {
			printf(" %d", stu[h][j]);
		}
		putchar('\n');
	}
	return 0;
}


