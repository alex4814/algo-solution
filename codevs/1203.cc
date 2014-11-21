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
	double x, y;
	scanf("%lf %lf", &x, &y);
	puts(sgn(x - y) == 0 ? "yes" : "no");
	return 0;
}


