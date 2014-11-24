#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXR 205

typedef pair<int, int> pii;
typedef long long ll;

struct Rich {
	char name[10];
	int age;
	int worth;
	bool operator < (const Rich &b) const {
		return (worth < b.worth) ||
					 (worth == b.worth && age > b.age) ||
					 (worth == b.worth && age == b.age && strcmp(name, b.name) > 0);
	}
};

Rich rich[MAXN];
int s[MAXR];	// s[i] for begin index of age i (in sorted rich)
int c[MAXR];

bool age_first_cmp(const Rich &a, const Rich &b) {
		return (a.age < b.age) || 
					 (a.age == b.age && a.worth > b.worth) ||
					 (a.age == b.age && a.worth == b.worth && strcmp(a.name, b.name) < 0);
}

int lower(int x, int n) {	
	int l = 0, r = n;
	while (l < r) {
		int m = l + (r - l) / 2;
		rich[m].age >= x ? r = m : l = m + 1;
	}
	return l;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s %d %d", rich[i].name, &rich[i].age, &rich[i].worth);
	}
	sort(rich, rich + n, age_first_cmp);
	for (int i = 1; i < MAXR; ++i) {
		s[i] = lower(i, n);
	}
	int m, la, ra;
	for (int nCase = 0; nCase < k; ++nCase) {
		scanf("%d %d %d", &m, &la, &ra);
		printf("Case #%d:\n", nCase + 1);
		priority_queue<Rich> heap;	// each produce one of first m maximums;
		for (int i = la; i <= ra; ++i) {
			c[i] = s[i];
		}
		// push first (ra - la + 1) items to build a heap
		for (int i = la; i <= ra; ++i) {
			if (c[i] != s[i + 1]) {
				heap.push(rich[ s[i] ]);
			}
		}
		int tot = 0;
		while (!heap.empty()) {
			Rich top = heap.top();
			heap.pop();
			printf("%s %d %d\n", top.name, top.age, top.worth);
			if (++tot == m) {
				break;
			}
			if (c[top.age] + 1 < s[top.age + 1]) {
				heap.push(rich[ ++c[top.age] ]);
			}
		}
		if (tot == 0) {
			printf("None\n");
		}
	}
	return 0;
}


