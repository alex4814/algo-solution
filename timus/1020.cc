#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 100
const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

typedef struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
} Vector;


inline double dis_pp(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point p[MAXN + 1];
int n;
double r;

int main() {
    scanf("%d %lf", &n, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    p[n] = p[0];

    double ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += dis_pp(p[i], p[i + 1]);
    }
    ret += 2 * PI * r;

    printf("%.2f\n", ret);
    return 0;
}
