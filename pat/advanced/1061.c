#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define min(a, b) (a) < (b) ? (a) : (b)

int len[4];
char msg[4][100];
char *day[] = {
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

int main() {
	int i, n, d, h, m, cnt;

	for (i = 0; i < 4; ++i) {
		scanf("%s", msg[i]);
		len[i] = strlen(msg[i]);
	}

	cnt = 0;
	n = min(len[0], len[1]);
	for (i = 0; i < n; ++i) {
		if (cnt && (isdigit(msg[0][i]) || (msg[0][i] >= 'A' && msg[0][i] <= 'N')) && msg[0][i] == msg[1][i]) {
			h = msg[0][i] - (isdigit(msg[0][i]) ? '0' : 'A' - 10);
			break;
		}
		if (!cnt && msg[0][i] == msg[1][i] && msg[0][i] >= 'A' && msg[0][i] <= 'G') {
			d = msg[0][i] - 'A'; cnt = 1;
		}
	}

	n = min(len[2], len[3]);
	for (i = 0; i < n; ++i) {
		if (isalpha(msg[2][i]) && msg[2][i] == msg[3][i]) {
			m = i; break;
		}
	}
	printf("%s %02d:%02d\n", day[d], h, m);
	return 0;
}

