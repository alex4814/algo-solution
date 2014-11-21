#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}

int main() {
	char time[6];
	while (scanf("%s", time) != EOF) {
		int h, m;
		sscanf(time, "%d:%d", &h, &m);
		if (h > 12) h -= 12;
		double rm = m * 6.0;
		double rh = h * 30.0 + m * 0.5;
		double rd = 0;
		if (sgn(rm - rh) > 0) {
			rd = rm - rh;
		} else {
			rd = rh - rm;
		}
		//printf("%.2f\n", rd);
		//printf("%.2f %.2f\n", rh, rm);
		//rabs += (sgn(rabs) < 0 ? 360 : 0);
		if (sgn(rd - 180) > 0) rd = 360 - rd;
		printf("%.2f\n", rd);
	}
	return 0;
}


