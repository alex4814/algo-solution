#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))
#define zero(x) (((x)>0?(x):-(x))<eps)

#define EPS 1e-8
#define eps 1e-8
#define _N 105
#define _M 105
#define PI acos(-1.0)

struct point{double x,y;};

inline int sgn(double x) {
	if (fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

inline double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

/*
#define offset 105
//判点在任意多边形内,顶点按顺时针或逆时针给出
//on_edge表示点在多边形边上时的返回值,offset为多边形坐标上限
int inside_polygon(point q,int n,point* p,int on_edge=0){
	point q2;
	int i=0,count;
	while (i<n)
		for (count=i=0,q2.x=rand()+offset,q2.y=rand()+offset;i<n;i++)
			if (zero(xmult(q,p[i],p[(i+1)%n]))&&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps&&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
				return on_edge;
			else if (zero(xmult(q,q2,p[i])))
				break;
			else if (xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-eps&&xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-eps)
				count++;
	return count&1;
}
*/

int is_point_on_segment(point p,point l1,point l2){
	return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}

int inside_polygon(point q, int n, point *p) {
	int wn = 0;
	for (int i = 0; i < n; ++i) {
		if (is_point_on_segment(q, p[i], p[(i+1)%n])) return 0;		// on edge;
		int k = sgn(xmult(p[i], p[(i+1)%n], q));
		int d1 = sgn(p[i].y - q.y);
		int d2 = sgn(p[(i+1)%n].y - q.y);
		if (k > 0 && d1 <= 0 && d2 > 0) wn++;
		if (k < 0 && d2 <= 0 && d1 > 0) wn--;
	}
	return wn != 0;
}

point bullet_moving(double g, double vb, double vp, double t) {
	point ret;
	ret.y = vb * t - 0.5 * g * t * t;
	ret.x = -vp * t;
	return ret;
}

point p[_N];
double v, v0, g, t;

#define ENUM 0.001

int main() {
	srand(unsigned(time(NULL)));
	int n, _t;
	while (scanf("%lf%lf%lf", &v, &v0, &g) == 3) {
		if (!v && !v0 && !g) break;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) { 
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}

		bool hit = false;
		t = 2 * v0 / g * 1000;
		for (_t = 0; _t < (int)t; ++_t) {
			double delta = _t * ENUM;
			point cur = bullet_moving(g, v0, v, delta);
			//printf("(%.3f, %.3f)\n", b.x, b.y);
			if (inside_polygon(cur, n, p)) {
				hit = true;
				break;
			}
		}
		hit ? printf("%.2f\n", _t * ENUM - 0.005) : printf("Miss!\n");
	}
	return 0;
}
