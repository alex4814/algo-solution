#include <stdio.h>

int main() {
	double f1, f2;
	int w;
	char s[2];
	scanf("%lf %d %s %lf", &f1, &w, s, &f2);
	printf("%s %d %.2f %.2f\n", s, w, f1, f2);
	return 0;
}
