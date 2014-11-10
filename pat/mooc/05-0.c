#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	double r = 0;
	double nr = 2, dr = 1, t;
	for (int i = 0; i < n; ++i) {
		r += (t = nr) / dr;
		nr = nr + dr;
		dr = t;
	}
	printf("%.2f\n", r);
	return 0;
}
