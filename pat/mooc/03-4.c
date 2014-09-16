#include <stdio.h>

int main() {
	int s;
	scanf("%d", &s);
	if (s >= 90) {
		puts("A");
	} else if (s >= 80) {
		puts("B");
	} else if (s >= 70) {
		puts("C");
	} else if (s >= 60) {
		puts("D");
	} else {
		puts("E");
	}
	return 0;
}
