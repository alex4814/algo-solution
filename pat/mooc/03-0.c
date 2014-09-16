#include <stdio.h>

int main() {
	int speed;
	scanf("%d", &speed);
	printf("Speed: %d - ", speed);
	puts(speed > 60 ? "Speeding" : "OK");
	return 0;
}
