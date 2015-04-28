#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 100
const double EPS = 1e-12;
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

Point p[MAXN], o;
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }

    double maxd = 0;
    for (int i = 0; i < n; ++i) {
        double d = dis_pp(o, p[i]);
        maxd = max(maxd, d);
    }
    printf("0 0 %.9f\n", maxd);

    return 0;
}

