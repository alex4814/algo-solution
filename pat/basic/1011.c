#include <stdio.h>
typedef long long ll;

int main() {
	ll a, b, c;
	int t, i;
	scanf("%d", &t);
	for (i = 1; i <= t; ++i) {
		scanf("%lld%lld%lld", &a, &b, &c);
		printf("Case #%d: %s\n", i, a + b > c ? "true" : "false");
	}
	return 0;
}
