#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

typedef struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
} Vector;

Vector operator + (Vector a, Vector b) {
	return Vector(a.x + b.x, a.y + b.y);
}
Vector operator - (Vector a, Vector b) {
	return Vector(a.x - b.x, a.y - b.y);
}
Vector operator * (Vector a, double k) {
	return Vector(a.x * k, a.y * k);
}
Vector operator / (Vector a, double k) {
	return Vector(a.x / k, a.y / k);
}
bool operator == (const Point &a, const Point &b) {
	return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}
bool operator < (const Point &a, const Point &b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

inline double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}
inline double cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}
inline double xmult(Point a, Point b, Point c) {
	return cross(b - a, c - a);
}
inline double length(Vector a) {
	return sqrt(dot(a, a));
}
inline double angle(Vector a, Vector b) {
	return acos(dot(a, b) / length(a) / length(b));
}
inline Vector rotate(Vector a, double rad) {
	return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}

inline double dis_pp(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline double dis_ps(Point p, Point a, Point b) {
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if (a == b) return length(p - a);
	if (sgn(dot(v1, v2)) < 0) return length(v2);
	if (sgn(dot(v1, v3)) > 0) return length(v3);
	return fabs(cross(v1, v2)) / length(v1);
}

Point A, B, C;
double L;

int main() {
    scanf("%lf %lf", &A.x, &A.y);
    scanf("%lf %lf", &B.x, &B.y);
    scanf("%lf %lf", &C.x, &C.y);
    scanf("%lf", &L);

    double least = dis_ps(C, A, B);
    double most = max(dis_pp(C, A), dis_pp(C, B));
    if (sgn(L - most) >= 0) {
        printf("0.00 0.00\n");
    } else if (sgn(L - least) >= 0) {
        printf("0.00 %.2f\n", most - L);
    } else {
        printf("%.2f %.2f\n", least - L, most - L);
    }
    return 0;
}
