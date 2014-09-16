#include <stdio.h>

int main() {
	int t, past, h, m;
	scanf("%d %d", &t, &past);
	m = t % 100;
	h = t / 100;
	t = h * 60 + m + past;
	m = t % 60;
	h = t / 60;
	printf("%d%02d\n", h, m);
	return 0;
}
