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
#define MAXL 10

typedef pair<int, int> pii;
typedef long long ll;

struct Record {
	int id;
	char name[MAXL];
	int grade;
};

bool compare_id(Record a, Record b) {
	return a.id < b.id;
}
bool compare_name(Record a, Record b) {
	return (strcmp(a.name, b.name) < 0) ||
				 (strcmp(a.name, b.name) == 0 && a.id < b.id);
}
bool compare_grade(Record a, Record b) {
	return (a.grade < b.grade) ||
				 (a.grade == b.grade && a.id < b.id);
}

Record rec[MAXN];

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d %s %d", &rec[i].id, rec[i].name, &rec[i].grade);
	}
	bool (*compare)(Record, Record);
	if (c == 1) {
		compare = compare_id;
	} else if (c == 2) {
		compare = compare_name;
	} else if (c == 3) {
		compare = compare_grade;
	}
	sort(rec, rec + n, compare);
	for (int i = 0; i < n; ++i) {
		printf("%06d %s %d\n", rec[i].id, rec[i].name, rec[i].grade);
	}
	return 0;
}


