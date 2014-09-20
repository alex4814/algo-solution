#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 505

const double EPS = 1e-8;
const double PI = acos(-1.0);

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
    bool operator < (const Segment &t) const {
        return a.x < t.a.x;
    }
};
struct Circle {
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0): c(c), r(r) {}
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

inline double dis_pp(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point intersection_ll(Point a, Vector i, Point b, Vector j) {
	Vector k = a - b;
	double t = cross(j, k) / cross(i, j);
	return a + i * t;
}
// 计算圆外一点与圆的两个切点
void point_of_tangency_cp(Circle c, Point p, Point &p1, Point &p2) {
    double d = dis_pp(c.c, p);
    double theta = asin(c.r / d);
    Vector v1 = rotate(c.c - p, theta);
    Vector v2 = rotate(c.c - p, 2 * PI - theta);
    p1 = p + v1 / length(v1) * d * cos(theta);
    p2 = p + v2 / length(v2) * d * cos(theta);
}

int seg_union(Segment *s, int &n) {
	int m = 0;
	for (int i = 1; i < n; ++i) {
		if (s[m].b.x < s[i].a.x) {
			s[++m] = s[i];
		} else {
			s[m].a.x = min(s[m].a.x, s[i].a.x);
			s[m].b.x = max(s[m].b.x, s[i].b.x);
		}
	}
	return n = m + 1;
}

Point p, o;
Vector x(1, 0);
Circle c[MAXN];
Segment s[MAXN];
int n;

int main() {
    Point a, b;

    while (scanf("%d", &n), n) {
        scanf("%lf %lf", &p.x, &p.y);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", &c[i].c.x, &c[i].c.y, &c[i].r);

            point_of_tangency_cp(c[i], p, a, b);
            a = intersection_ll(p, a - p, o, x);
            b = intersection_ll(p, b - p, o, x);

            if (sgn(a.x - b.x) > 0) swap(a, b);
            s[i] = Segment(a, b);
        }
        sort(s, s + n);

        int m = seg_union(s, n);
        for (int i = 0; i < m; ++i) {
            printf("%.2f %.2f\n", s[i].a.x, s[i].b.x);
        }
        printf("\n");
    }
    return 0;
}
