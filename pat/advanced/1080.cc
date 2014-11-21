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
#define MAXN 40005
#define MAXM 105

typedef pair<int, int> pii;
typedef long long ll;

struct Student {
	int id, rank;
	int ge, gi;
	int p[5];
	bool operator < (const Student &b) const {
		return (ge + gi > b.ge + b.gi) || ((ge + gi == b.ge + b.gi) && ge > b.ge);
	}
	bool operator == (const Student &b) const {
		return ge + gi == b.ge + b.gi && ge == b.ge;
	}
};

int quota[MAXM];
int lrank[MAXM];
Student s[MAXN];
vector<int> c[MAXM];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d", quota + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &s[i].ge, &s[i].gi);
		s[i].id = i;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &s[i].p[j]);
		}
	}
	sort(s, s + n);
	for (int i = 0; i < n; ++i) {
		s[i].rank = i + 1;
		if (i && s[i] == s[i - 1]) {
			s[i].rank = s[i - 1].rank;
		}
		for (int j = 0; j < k; ++j) {
			int preferred = s[i].p[j];
			if (quota[preferred] <= 0 && s[i].rank != lrank[preferred]) continue;
			c[preferred].push_back(s[i].id);
			lrank[preferred] = s[i].rank;
			quota[preferred] -= 1;
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		sort(c[i].begin(), c[i].end());
		int sz = c[i].size();
		for (int j = 0; j < sz; ++j) {
			if (j) putchar(' ');
			printf("%d", c[i][j]);
		}
		putchar('\n');
	}
	return 0;
}


