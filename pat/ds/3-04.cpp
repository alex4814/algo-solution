#include <cstdio>
#include <map>
using namespace std;

#define MAXN 1000
struct Item {
	int c, e;
};

int n1, n2, ix;
Item p1[MAXN], p2[MAXN];
Item pm[MAXN], pa[MAXN];
map<int, int, greater<int> > etoc;
map<int, int>::iterator it;

int main() {
	scanf("%d", &n1);
	for (int i = 0; i < n1; ++i) {
		scanf("%d%d", &p1[i].c, &p1[i].e);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; ++i) {
		scanf("%d%d", &p2[i].c, &p2[i].e);
	}

	etoc.clear();
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			etoc[ p1[i].e + p2[j].e ] += p1[i].c * p2[j].c;
		}
	}
	ix = 0;
	for (it = etoc.begin(); it != etoc.end(); ++it) {
		if (it->second != 0) {
			if (ix++) putchar(' ');
			printf("%d %d", it->second, it->first);
		}
	}
	if (!ix) printf("0 0");
	putchar('\n');
	
	etoc.clear();
	for (int i = 0; i < n1; ++i) {
		etoc[ p1[i].e ] += p1[i].c;
	}
	for (int i = 0; i < n2; ++i) {
		etoc[ p2[i].e ] += p2[i].c;
	}
	ix = 0;
	for (it = etoc.begin(); it != etoc.end(); ++it) {
		if (it->second != 0) {
			if (ix++) putchar(' ');
			printf("%d %d", it->second, it->first);
		}
	}
	if (!ix) printf("0 0");
	putchar('\n');
	return 0;
}
