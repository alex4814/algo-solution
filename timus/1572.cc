#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 100
const double EPS = 1e-8;
const double PI = acos(-1.0);

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

struct Figure {
    int type;
    double size;
};

// 1 for circle, 2 for square, 3 for triangle
double range[4];
int n;

Figure well, c;

void cal_range() {
    if (well.type == 1) {
        range[1] = well.size;
        range[2] = well.size * 2;
        range[3] = well.size * 4 / sqrt(3);
    } else if (well.type == 2) {
        range[1] = well.size / sqrt(2);
        range[2] = well.size * sqrt(2);
        range[3] = well.size * sqrt(8) / sqrt(3);
    } else {
        range[1] = well.size / 2;
        range[2] = well.size;
        range[3] = well.size * 2 / sqrt(3);
    }
}

int main() {
    scanf("%d %lf", &well.type, &well.size);
    cal_range();

    int ret = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &c.type, &c.size);
        if (sgn(c.size - range[ c.type ]) <= 0) {
            ret = ret + 1;
        }
    }
    printf("%d\n", ret);

    return 0;
}
