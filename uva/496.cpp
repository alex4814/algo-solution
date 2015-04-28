#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define _N 100005
#define _M 105
#define PI acos(-1.0)

char _a[_N], _b[_N];
vector<int> a, b;

int solve()
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	bool disjoint = true, same = true;
	bool a_b = true, b_a = true;

	if ((int)a.size() == (int)b.size()) {
		a_b = b_a = false;
		FOR (i, 0, (int)a.size()) {
			if (a[i] != b[i]) { same = false; }
			binary_search(b.begin(), b.end(), a[i]) ? disjoint = false : NULL;
		}
	} else if ((int)a.size() < (int)b.size()) {
		same = b_a = false;
		FOR (i, 0, (int)a.size()) {
			binary_search(b.begin(), b.end(), a[i]) ? disjoint = false : a_b = false;
		}
	} else {
		same = a_b = false;
		FOR (i, 0, (int)b.size()) {
			binary_search(a.begin(), a.end(), b[i]) ? disjoint = false : b_a = false;
		}
	}
	if (same) return 1;
	if (a_b) return 2;
	if (b_a) return 3;
	if (disjoint) return 4;
	return 0;
}

int main()
{
	while (fgets(_a, _N, stdin) != NULL) {
		a.clear(); b.clear();
		fgets(_b, _N, stdin);
		char *p = strtok(_a, " \n");
		while (p != NULL) {
			a.push_back(atoi(p));
			p = strtok(NULL, " \n");
		}

		p = strtok(_b, " \n");
		while (p != NULL) {
			b.push_back(atoi(p));
			p = strtok(NULL, " \n");
		}

		int result = solve();
		if (result == 1) {
			puts("A equals B");
		} else if (result == 2) {
			puts("A is a proper subset of B");
		} else if (result == 3) {
			puts("B is a proper subset of A");
		} else if (result == 4) {
			puts("A and B are disjoint");
		} else {
			puts("I'm confused!");
		}
	}
	return 0;
}
