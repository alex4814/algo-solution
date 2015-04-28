#include <cstdio>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t); while (t--) {
		scanf("%d", &n);
		int rm = n % 10;
		int ret = rm;
		int k = -1;
		for (int i = 1; i < n; ++i) {
			ret = ret * rm % 10;
			if (ret == rm) {
				k = i; break;
			}
		}
		n = (n - 1) % k;
		for (int i = 0; i < n; ++i) {
			ret = ret * rm % 10;
		}
		printf("%d\n", ret);
	}
	return 0;
}
