#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 200

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

Point p[MAXN];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                if (sgn(cross(p[i] - p[k], p[j] - p[k])) == 0) {
                    ++cnt;
                }
            }
            ret = max(ret, cnt);
        }
    }
    printf("%d\n", ret + 2);

    return 0;
}

