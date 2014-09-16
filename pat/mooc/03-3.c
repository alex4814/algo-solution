#include <stdio.h>

int main() {
	char t[10];
	scanf("%s", t);
	int h, m;
	sscanf(t, "%d:%d", &h, &m);
	char pm = 0;
	if (h >= 12) {
		pm = 1;
		if (h > 12) {
			h -= 12;
		}
	}
	printf("%d:%d ", h, m);
	puts(pm ? "PM" : "AM");
	return 0;
}
