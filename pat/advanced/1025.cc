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
#define MAXN 30005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct Testee {
	char id[14];
	int score;
	int lnumber;
	int frank;
	int lrank;
	bool operator < (const Testee &b) const {
		return score > b.score || (score == b.score && strcmp(id, b.id) < 0);
	}
};

Testee a[MAXN];

int main() {
	int n, k;
	scanf("%d", &n);
	int cb = 0; // current begin
	for (int ln = 0; ln < n; ++ln) {
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			scanf("%s %d", a[cb + i].id, &a[cb + i].score);
			a[cb + i].lnumber = ln + 1;
		}
		sort(a + cb, a + cb + k);
		a[cb].lrank = 1;
		for (int i = 1; i < k; ++i) {
			a[cb + i].lrank = i + 1;
			if (a[cb + i].score == a[cb + i - 1].score) {
				a[cb + i].lrank = a[cb + i - 1].lrank;
			}
		}
		cb += k;
	}
	n = cb; 	// total #testees
	sort(a, a + n);
	a[0].frank = 1;
	for (int i = 1; i < n; ++i) {
		a[i].frank = i + 1;
		if (a[i].score == a[i - 1].score) {
			a[i].frank = a[i - 1].frank;
		}
	}
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%s %d %d %d\n", a[i].id, a[i].frank, a[i].lnumber, a[i].lrank);
	}
	return 0;
}


