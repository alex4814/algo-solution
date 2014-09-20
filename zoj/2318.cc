#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-6
#define INF 1e10
#define MAXV 305
#define MAXE 90005

typedef pair<int, int> pii;
typedef long long ll;

typedef struct Point {
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}	
} Vector;

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}
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
inline double length(Vector a) {
	return sqrt(dot(a, a));
}
inline double angle(Vector a, Vector b) {
	return acos(dot(a, b) / length(a) / length(b));
}
inline double dis_pp(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int T, n, m;
Point c[MAXV], p;
double r[MAXV];

int first[MAXV], nxt[MAXE];
int u[MAXE], v[MAXE];
double w[MAXE];

void add_edge(int x, int y, int e, double a) {
	u[e] = x, v[e] = y, w[e] = a;
	nxt[e] = first[x];
	first[x] = e;
}
void build_graph() {
	memset(first, -1, sizeof(first));

	m = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double d = dis_pp(c[i], c[j]);
			if (sgn(d - r[i] - r[j]) < 0) {
				double theta = angle(c[i] - p, c[j] - p);
				int sf = sgn(cross(c[i] - p, c[j] - p));
				add_edge(i, j, m++, sf * theta);
				add_edge(j, i, m++, -sf * theta);
			}
		}
	}
}

double d[MAXV];	// distance

// queue-based improvement
// n vertices and m edges
// vertex start from 0
bool bellman_ford(int s) {
	static bool inq[MAXV];
	static int cnt[MAXV];
	queue<int> q;

	memset(inq, false, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	d[s] = 0;

	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		inq[x] = false;
		for (int e = first[x]; e != -1; e = nxt[e]) {
			if (sgn(d[ v[e] ] - (d[x] + w[e])) > 0) {
				d[ v[e] ] = d[x] + w[e];
				if (!inq[ v[e] ]) {
					inq[ v[e] ] = true;
					q.push(v[e]);
					if (++cnt[ v[e] ] == n) return false;
				}
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &T);
	
	for (int nCase = 1; nCase <= T; ++nCase) {
		if (nCase != 1) putchar('\n');

		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf %lf", &c[i].x, &c[i].y, r + i);
		}
		scanf("%lf %lf %lf", &p.x, &p.y, r + n);
		for (int i = 0; i < n; ++i) {
			r[i] += r[n];
		}

		build_graph();

		bool yes = true;
		for (int i = 0; i < n; ++i) {
			d[i] = INF;
		}
		for (int i = 0; i < n; ++i) {
			if (sgn(d[i] - INF) == 0 && bellman_ford(i) == false) {
				yes = false;
				break;
			}
		}
		puts(yes ? "YES" : "NO");
	}

	return 0;
}


