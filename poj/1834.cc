#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 100005

const double EPS = 1e-8;
const double PI = M_PI;

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

typedef struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
} Vector;

struct Segment {
	Point a, b;
	Segment(Point a = Point(), Point b = Point()): a(a), b(b) {}
};

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

inline bool is_proper_intersection_ss(Point a1, Point a2, Point b1, Point b2) {
	double d1 = cross(a2 - a1, b1 - a1), d2 = cross(a2 - a1, b2 - a1);
	double d3 = cross(b2 - b1, a1 - b1), d4 = cross(b2 - b1, a2 - b1);
	return sgn(d1) * sgn(d2) < 0 && sgn(d3) * sgn(d4) < 0;
}
inline bool is_on_ps(Point p, Point a, Point b) {
	return sgn(cross(a - p, b - p)) == 0 && sgn(dot(a - p, b - p)) < 0;
}
Point intersection_ll(Point a, Vector i, Point b, Vector j) {
	Vector k = a - b;
	double t = cross(j, k) / cross(i, j);
	return a + i * t;
}

int n_case;
int n1, n2;

int main() {
	scanf("%d", &n_case);
	for (int c = 0; c < n_case; ++c) {
		scanf("%d %d", &n1, &n2);
		for (int i = 0; i < n2; ++i) {
			int k1, p1, k2, p2;
			scanf("%d %d", &k1, &p1);
			scanf("%d %d", &k2, &p2);
		}
	}
	return 0;
}
