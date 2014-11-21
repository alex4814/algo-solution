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
#define MAXL 15

typedef pair<int, int> pii;
typedef long long ll;

struct Record {
	char name[MAXL];
	char id[MAXL];
	int score;
	bool operator < (const Record &b) const {
		return score > b.score;
	}
};

Record r[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s %d", r[i].name, r[i].id, &r[i].score);
	}
	int s, t;
	scanf("%d %d", &s, &t);
	sort(r, r + n);
	int i = lower_bound(r, r + n, (Record){"", "", t}) - r;
	int j = upper_bound(r, r + n, (Record){"", "", s}) - r;
	if (i == j) {
		puts("NONE");
	} else {
		for (int k = i; k < j; ++k) {
			printf("%s %s\n", r[k].name, r[k].id);
		}
	}
	return 0;
}


