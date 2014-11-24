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
#define MAXN 10005
#define MAXM 105

struct Record {
	char id[20];
	char in[10], out[10];
}r[MAXN];

bool first(Record a, Record b) {
	return strcmp(a.in, b.in) < 0;
}
bool last(Record a, Record b) {
	return strcmp(a.out, b.out) > 0;
}
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s%s%s", r[i].id, r[i].in, r[i].out);
	}
	sort(r, r + n, first);
	printf("%s ", r[0].id);
	sort(r, r + n, last);
	printf("%s\n", r[0].id);
	return 0;
}
