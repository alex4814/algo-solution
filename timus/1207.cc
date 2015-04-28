#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 10000

typedef struct Point {
	double x, y;
    double a;
    int id;
	Point(double x = 0, double y = 0): x(x), y(y) {}
} Vector;

bool operator < (const Point &a, const Point &b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool compare_with_angle(const Point &a, const Point &b) {
    return a.a < b.a;
}

Point p[MAXN];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
        p[i].id = i + 1;
    }

    sort(p, p + n);
    for (int i = 1; i < n; ++i) {
        p[i].x -= p[0].x;
        p[i].y -= p[0].y;
        p[i].a = atan2(p[i].y, p[i].x);
    }
    p[0].x = p[0].y = 0;

    sort(p + 1, p + n, compare_with_angle);
    printf("%d %d\n", p[0].id, p[n / 2].id);

    return 0;
}
