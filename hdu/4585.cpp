#include <cstdio>
#include <set>
using namespace std;

struct Monk {
	int id, grade;
	bool operator < (const Monk &b) const {
		return grade < b.grade;
	}
}next;

set<Monk> monk;
set<Monk>::iterator it;

int main() {
	int n;
	while (scanf("%d", &n), n) {
		monk.clear();

		next = (Monk){ 1, 1000000000 };
		monk.insert(next);

		for (int i = 0, k, g; i < n; ++i) {
			scanf("%d%d", &k, &g);
			next = (Monk){ k, g };

			Monk x, y = *(it = monk.upper_bound(next));
			if (it != monk.begin()) {
				x = *(--it);
				printf("%d %d\n", k, g - x.grade <= y.grade - g ? x.id : y.id);
			} else {
				printf("%d %d\n", k, y.id);
			}

			monk.insert(next);
		}
	}
	return 0;
}
