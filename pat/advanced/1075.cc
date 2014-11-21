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
#define MAXN 10005
#define MAXP 6

typedef pair<int, int> pii;
typedef long long ll;

struct User {
	int id;
	int s[MAXP];	// score for each problem, s[0] for number of perfectly solved
	int ts;	// total score;
	int rank;
	bool submitted;
	bool operator < (const User &b) const {
		return (ts > b.ts) || 
					 (ts == b.ts && s[0] > b.s[0]) || 
					 (ts == b.ts && s[0] == b.s[0] && id < b.id);
	}
};

User user[MAXN];
int p[MAXP];	// full score of problems

int main() {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", p + i);
	}
	for (int i = 1; i <= n; ++i) {
		fill(user[i].s + 1, user[i].s + 1 + k, -2);
	}
	for (int i = 0; i < m; ++i) {
		int id, pid, pso;
		scanf("%d %d %d", &id, &pid, &pso);
		user[id].id = id;
		user[id].s[pid] = max(user[id].s[pid], pso);
	}
	for (int i = 1; i <= n; ++i) {
		user[i].s[0] = 0;
		user[i].ts = 0; 
		for (int j = 1; j <= k; ++j) {
			if (user[i].s[j] >= 0) {
				user[i].submitted = true;
				user[i].ts += user[i].s[j];
			}
			if (user[i].s[j] == p[j]) {
				user[i].s[0] += 1;
			}
		}
	}
	sort(user + 1, user + 1 + n);
	for (int i = 1; i <= n; ++i) {
		user[i].rank = i;
		if (user[i].ts == user[i - 1].ts) {
			user[i].rank = user[i - 1].rank;
		}
		if (!user[i].submitted) {
			continue;
		}
		printf("%d %05d %d", user[i].rank, user[i].id, user[i].ts);
		for (int j = 1; j <= k; ++j) {
			int pt = user[i].s[j];
			if (pt == -2) {
				printf(" -");
			} else {
				printf(" %d", max(0, pt));
			}
		}
		putchar('\n');
	}
	return 0;
}


