#include <cstdio>
using namespace std;

char date[10];
int year, month, day;

int days[2][13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

bool is_leap_year(int y) {
	return (y % 400 == 0) || (y % 4 == 0 && y % 100);
}

int main() {
	while (scanf("%s", date) == 1) {
		sscanf(date, "%d/%d/%d", &year, &month, &day);
		int leap = is_leap_year(year) ? 1 : 0;
		int sum = 0;
		for (int i = 1; i < month; ++i) {
			sum += days[leap][i];
		}
		sum += day;
		printf("%d\n", sum);
	}
	return 0;
}
