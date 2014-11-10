#include <stdio.h>

int main() {
	int x, n;
	scanf("%d %d", &x, &n);
	int g, cnt = 1, lose = 1;
	while (scanf("%d", &g), g >= 0) {
		if (cnt > n) break;
		if (g == x) {
			lose = 0;
			break;
		} else if (g > x) {
			puts("Too big");
		} else {
			puts("Too small");
		}
		++cnt;
	}
	if (lose) {
		puts("Game Over");
	} else {
		if (cnt == 1) {
			puts("Bingo!");
		} else if (cnt <= 3) {
			puts("Lucky You!");
		} else {
			puts("Good Guess!");
		}
	}
	return 0;
}
