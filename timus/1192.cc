#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = 3.1415926535;
const double G = 10;

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

double v, a, k;

typedef struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
} Vector;

int main() {
    scanf("%lf %lf %lf", &v, &a, &k);

    double _a = a / 180 * PI;
    double ret = 0;
    while (sgn(v) > 0) {
        double x = 2 * v * v * sin(_a) * cos(_a) / G;
        ret += x;

        v = v / sqrt(k);
    }
    printf("%.2f\n", ret);
    return 0;
}
