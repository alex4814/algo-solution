#include <cstdio>
using namespace std;

int main() {
	int x, y;
	while (scanf("%d %d", &x, &y) == 2) {
		if (y % x) {
			printf("0\n"); continue;
		}
		int numberOfFactors = 0;
		int m = y / x;
		for (int i = 2; i * i <= m; ++i) {
			if (m % i == 0) {
				++numberOfFactors;
				while (m % i == 0) m /= i;
			}
		}
		if (m != 1) ++numberOfFactors;
		printf("%lld\n", (1ll << numberOfFactors));
	}
	return 0;
}
