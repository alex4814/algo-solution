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
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

struct Person {
	char name[6];
	char date[11];
};

Person p[MAXN];
const char today[] = "2014/09/06";

int age(char *b) {
	int ty, tm, td;
	sscanf(today, "%d/%d/%d", &ty, &tm, &td);
	int by, bm, bd;
	sscanf(b, "%d/%d/%d", &by, &bm, &bd);
	int r = ty - by;
	if (tm > bm || (tm == bm && td > bd)) r++;
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	char birthday[11];
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", p[i].name, p[i].date);
	}
	int nValid = 0, o = -1, y = -1;
	for (int i = 0; i < n; ++i) {
		if (strcmp(p[i].date, today) > 0) continue;
		if (age(p[i].date) > 200) continue;
		if (o == -1 || y == -1) o = y = i;
		if (strcmp(p[i].date, p[o].date) < 0) o = i;
		if (strcmp(p[i].date, p[y].date) > 0) y = i;
		++nValid;
	}
	if (nValid == 0) {
		printf("0\n");
	} else {
		printf("%d %s %s\n", nValid, p[o].name, p[y].name);
	}
	return 0;
}


