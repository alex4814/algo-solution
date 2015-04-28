#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

double a, r;

int main() {
    scanf("%lf %lf", &a, &r);
    a /= 2;
    if (sgn(r - a) <= 0) {
        printf("%.3f\n", PI * r * r);
    } else if (sgn(r - a * sqrt(2)) <= 0) {
        double theta = acos(a / r);
        printf("%.3f\n", PI * r * r - 4 * (r * r * theta - r * a * sin(theta)));
    } else {
        printf("%.3f\n", 4 * a * a);
    }
    return 0;
}
