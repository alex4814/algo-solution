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

struct Student {
	char name[MAXL];
	char gender[2];
	char id[MAXL];
	int grade;
	bool operator < (const Student &b) const {
		return (gender[0] < b.gender[0]) ||
			     (gender[0] == b.gender[0] && grade > b.grade);
	}
};

Student s[MAXN];

bool print(Student *a, char g) {
	if (a->gender[0] != g) {
		printf("Absent\n");
		return true;
	}
	printf("%s %s\n", a->name, a->id);
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", s[i].name, s[i].gender);
		scanf("%s %d", s[i].id, &s[i].grade);
	}
	sort(s, s + n);
	bool absent = false;
	absent |= print(&s[0], 'F');
	absent |= print(&s[n - 1], 'M');
	if (absent) {
		printf("NA\n");
	} else {
		printf("%d\n", s[0].grade - s[n - 1].grade);
	}
	return 0;
}


