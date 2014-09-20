#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 25

const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

typedef struct Point {
	double x, y;
    int id;
	Point(double x = 0, double y = 0): x(x), y(y) {}
} Vector;

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
inline double dis_pl(Point p, Point a, Point b) {
	Vector v1 = b - a, v2 = p - a;
	return fabs(cross(v1, v2)) / length(v1);
}
Point intersection_ll(Point a, Vector i, Point b, Vector j) {
	Vector k = a - b;
	double t = cross(j, k) / cross(i, j);
	return a + i * t;
}
// -1 for d > r, 0 for d == r, 1 for d < r
inline int relative_position_cp(Circle c, Point p) {
    double d = dis_pp(c.c, p);
    return sgn(c.r - d);
}
// -1 for d > r, 0 for d == r, 1 for d < r
inline int relative_position_lc(Point p, Vector v, Circle c) {
    double d = dis_pl(c.c, p, p + v);
    return sgn(c.r - d);
}

Point symmetry_pl(Point p, Point a, Point b) {
    Vector v1 = b - a, v2 = Vector(-v1.y, v1.x);
    Point m = intersection_ll(a, v1, p, v2);
    return p + (m - p) * 2;
}

// 计算直线与圆的交点,保证直线与圆有交点
// 计算线段与圆的交点可用这个函数后判点是否在线段上
void intersection_cl(Circle c, Point p, Vector v, Point &p1, Point &p2) {
    Point l1 = p, l2 = p + v;
    Vector u = Vector(-v.y, v.x);
    //Vector u = rotate(v, PI / 2.0);
	Point p0 = intersection_ll(p, v, c.c, u);
    double d1 = dis_pp(p0, c.c);
    double d2 = dis_pp(l1, l2);
	double t = sqrt(c.r * c.r - d1 * d1)/ d2;
	p1.x = p0.x + (l2.x - l1.x) * t;
	p1.y = p0.y + (l2.y - l1.y) * t;
	p2.x = p0.x - (l2.x - l1.x) * t;
	p2.y = p0.y - (l2.y - l1.y) * t;
}

Circle c[MAXN];
Point p;
Vector v;
int n;

typedef pair<Point, double> pPd;

bool cmp(pPd a, pPd b) {
    return a.second < b.second;
}

void test() {
    Point o;
    Point a(1, 1), b(1, 10);
    Point s = symmetry_pl(o, a, b);
    printf("%.2f %.2f\n", s.x, s.y);
}

int main() {
    static int n_case = 0;
    static vector<pPd> e;
    static vector<int> ret;

    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", &c[i].c.x, &c[i].c.y, &c[i].r);
            c[i].c.id = i + 1;
        }
        scanf("%lf %lf", &p.x, &p.y);
        scanf("%lf %lf", &v.x, &v.y);

        bool over = false;
        int tot = 11;

        ret.clear();
        while (!over && tot--) {
            bool collide = false;
            Point p1, p2;

            e.clear();
            for (int i = 0; i < n; ++i) {
                if (relative_position_cp(c[i], p) == 0) continue;
                if (dot(c[i].c - p, v) < 0) continue;
                if (relative_position_lc(p, v, c[i]) > 0) {
                    collide = true;
                    intersection_cl(c[i], p, v, p1, p2);
                    p1.id = p2.id = c[i].c.id;

                    e.push_back(make_pair(p1, dis_pp(p, p1)));
                    e.push_back(make_pair(p2, dis_pp(p, p2)));
                }
            }
            sort(e.begin(), e.end(), cmp);
            Point cp = e[0].first;

            if (collide) {
                ret.push_back(cp.id);
                v = symmetry_pl(p, c[ cp.id - 1 ].c, cp) - cp;
                p = cp;
            } else {
                over = true;
            }

            //printf("current p = %.2f %.2f, v = %.2f %.2f\n", p.x, p.y, v.x, v.y);
        }

        printf("Scene %d\n", ++n_case);
        int x = min(10, (int)ret.size());
        for (int i = 0; i < x; ++i) {
            printf("%d ", ret[i]);
        }
        puts(over ? "inf\n" : "...\n");
    }
    return 0;
}
