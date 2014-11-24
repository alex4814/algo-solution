#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 2005
#define MAXM 105

struct Student {
	int id;
	int a, c, m, e;
	int rank[4];
};

bool id(Student a, Student b) {
	return a.id < b.id;
}
bool avg(Student a, Student b) {
	return a.a > b.a;
}
bool cpl(Student a, Student b) {
	return a.c > b.c;
}
bool math(Student a, Student b) {
	return a.m > b.m;
}
bool en(Student a, Student b) {
	return a.e > b.e;
}

Student s[MAXN];
char p[] = "ACME";
int n, m, ix;

int bins(int l, int r, int x) {
	while (l <= r) {
		int m = (l + r) / 2;
		if (s[m].id == x) return m;
		s[m].id < x ? l = m + 1 : r = m - 1;
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &s[i].id, &s[i].c, &s[i].m, &s[i].e);
		s[i].a = s[i].c + s[i].m + s[i].e;
	}
	sort(s, s + n, avg);
	s[0].rank[0] = 1;
	for (int i = 1; i < n; ++i) {
		s[i].rank[0] = i + (s[i].a == s[i - 1].a ? 0 : 1);
	}
	sort(s, s + n, cpl);
	s[0].rank[1] = 1;
	for (int i = 0; i < n; ++i) {
		s[i].rank[1] = i + (s[i].c == s[i - 1].c ? 0 : 1);
	}
	sort(s, s + n, math);
	s[0].rank[2] = 1;
	for (int i = 0; i < n; ++i) {
		s[i].rank[2] = i + (s[i].m == s[i - 1].m ? 0 : 1);
	}
	sort(s, s + n, en);
	s[0].rank[3] = 1;
	for (int i = 0; i < n; ++i) {
		s[i].rank[3] = i + (s[i].e == s[i - 1].e ? 0 : 1);
	}
	sort(s, s + n, id);

	for (int i = 0, q; i < m; ++i) {
		scanf("%d", &q);
		if ((ix = bins(0, n - 1, q)) == -1) {
			printf("N/A\n");
		} else {
			int mix = 0;
			for (int j = 0; j < 4; ++j) {
				if (s[ix].rank[mix] > s[ix].rank[j]) {
					mix = j;
				}
			}
			printf("%d %c\n", s[ix].rank[mix], p[mix]);
		}
	}

	return 0;
}
