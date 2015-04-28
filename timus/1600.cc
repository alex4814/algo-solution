#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 500
const double EPS = 1e-9;
const double PI = acos(-1.0);

inline int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

typedef struct Point3 {
	double x, y, z;
	Point3(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
} Vector3 ;

Vector3 operator + (Vector3 a, Vector3 b) {
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}
Vector3 operator - (Point3 a, Point3 b) {
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}
Vector3 operator * (Vector3 a, double k) {
	return Vector3(a.x * k, a.y * k, a.z * k);
}
Vector3 operator / (Vector3 a, double k) {
	return Vector3(a.x / k, a.y / k, a.z / k);
}
inline double dot(Vector3 a, Vector3 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline double length(Vector3 a) {
	return sqrt(dot(a, a));
}

inline double dis_pp(Point3 a, Point3 b) {
    return length(a - b);
}

Point3 p[MAXN];
Vector3 v[MAXN];

int n;
double d;

int main() {
    scanf("%d %lf", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
        scanf("%lf %lf %lf", &v[i].x, &v[i].y, &v[i].z);
    }

    bool alarm = false;
    double ret = 1e20;
    int ra, rb;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double a = dot(v[i] - v[j], v[i] - v[j]);
            double b = 2 * dot(v[i] - v[j], p[i] - p[j]);
            double c = dot(p[i] - p[j], p[i] - p[j]) - d * d;

            double delta = b * b - 4 * a * c;
            if (sgn(delta) < 0) continue;

            double t1 = (-b - sqrt(delta)) / 2 / a;
            double t2 = (-b + sqrt(delta)) / 2 / a;

            double t0 = max(0.0, min(t1, t2));
            if (sgn(t0) == 0) continue;

            alarm = true;
            if (sgn(t0 - ret) < 0) {
                ra = i, rb = j;
                ret = t0;
            }
        }
    }

    alarm ? printf("ALARM!\n%.3f %d %d\n", ret, ra + 1, rb + 1) : printf("OK\n");
    return 0;
}
