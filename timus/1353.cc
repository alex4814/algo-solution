#include <cstdio>
using namespace std;

#define MAX_LENS 9
#define MAX_SUM 81
#define SUM_OF_DIGITS_OF_BILLION 1

int f[MAX_LENS + 1][MAX_SUM + 1];
int s;

int main() {
    scanf("%d", &s);

    for (int i = 1; i <= 9; ++i) {
        f[1][i] = 1;
    }
    for (int len = 2; len <= MAX_LENS; ++len) {
        for (int sum = 1; sum <= len * 9; ++sum) {
            for (int i = 0; i <= 9; ++i) {
                if (sum - i < 0) continue;
                f[len][sum] += f[len - 1][sum - i];
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= 9; ++i) {
        ret += f[i][s];
    }
    ret += s == 1 ? SUM_OF_DIGITS_OF_BILLION : 0;
    printf("%d\n", ret);
    return 0;
}

