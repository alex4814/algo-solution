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

int main() {
	int p;
	double d;
	scanf("%d %lf", &p, &d);
	int cp = p * d / 10.0;
	if (cp % 10 >= 5) {
		cp += 10;
	}
	printf("%d\n", cp / 10 * 10);
	return 0;
}


