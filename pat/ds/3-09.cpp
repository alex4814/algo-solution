#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100005

int a[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i) {
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);
	return 0;
}


